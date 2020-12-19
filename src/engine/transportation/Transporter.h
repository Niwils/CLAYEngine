/*
 * The <unnamed> factory builder project.
 *
 * \file /src/engine/transportation/Transporter.h
 *
 * \brief A transporter is an object representing a forklift, train... It carries an ItemContainer.
 */

/*
 * CHANGELOG:
 * 17/12/2020: File creation (NG)
 */

#ifndef FACTORYBUILDER_TRANSPORTER_H
#define FACTORYBUILDER_TRANSPORTER_H

#include <IToken.h>
#include <ItemContainer.h>
#include <Transportation.h>


class Transporter : public IToken
{
public:
    Transporter(s_ItemContainerQty _nbMaxContainer, TransporterDefinition _definition);
    ~Transporter();

    bool addItemContainer(ItemContainer *_container);
    ItemContainer *getItemContainer(s_ItemTypeUUID _itemType);

    bool moveToNextTile();
    bool isLoading();
    bool waitingToMove();
    bool isMoving();
    bool isUnloading();

    void runTick();
private:
    TransporterDefinition m_transporterRules;
    s_NumberofRounds m_remainingTicksCurrentState;
    s_ItemContainerQty m_nbMaxContainers;
    s_ItemContainerQty m_CurrentNbContainers;

    ObjList<ItemContainer> *mt_Containers;

    enum eTransporterState
    {
        eTransporterState_Idle,
        eTransporterState_Loading,
        eTransporterState_Awaiting,
        eTransporterState_Moving,
        eTransporterState_Unloading
    };

    eTransporterState m_State;
};


#endif //FACTORYBUILDER_TRANSPORTER_H
