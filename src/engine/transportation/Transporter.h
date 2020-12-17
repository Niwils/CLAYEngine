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

class Transporter : IToken
{
public:
    Transporter(s_ItemContainerQty _nbMaxContainer);
    ~Transporter();

    bool addItemContainer(ItemContainer *_container);
    ItemContainer *getItemContainer(s_ItemTypeUUID _itemType);

    bool waitingForLoading();
    bool isLoading();
    bool waitingToMove();
    bool isMoving();
    bool waitingToUnload();
    bool isUnloading();

    void runTick();
private:
    s_ItemContainerQty m_nbMaxContainers;
    s_ItemContainerQty m_CurrentNbContainers;

    ObjList<ItemContainer> *mt_Containers;

    enum eTransporterState
    {
        eTransporterState_Idle,
        eTransporterState_AwaitingToLoad,
        eTransporterState_Loading,
        eTransporterState_AwaitingToMove,
        eTransporterState_Moving,
        eTransporterState_AwaitingToUnload,
        eTransporterState_Unloading
    };

    eTransporterState m_State;
};


#endif //FACTORYBUILDER_TRANSPORTER_H