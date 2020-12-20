/**
 * The CLAYEngine project.
 *
 * @file /src/engine/transportation/Transporter.h
 *
 * @brief A transporter is an object representing a forklift, train... It carries an ItemContainer.
 */

/*
 * CHANGELOG:
 * 17/12/2020: File creation (NG)
 */

#ifndef FACTORYBUILDER_TRANSPORTER_H
#define FACTORYBUILDER_TRANSPORTER_H

#include <GraphCourse.h>
#include <IToken.h>
#include <ITransportationNode.h>
#include <ItemContainer.h>
#include <Transportation.h>


class Transporter : public IToken, public IGraphCourseSubscriber
{
public:
    /**
     * @brief The Transporter constructor.
     * @param _nbMaxContainer Maximum number of containers the Transporter can carry.
     * @param _definition Contains the number of rounds required to perform loading, unloading, and to cross a tile.
     */
    Transporter(s_ItemContainerQty _nbMaxContainer, TransporterDefinition _definition);
    virtual ~Transporter();

    /**
     * @brief Add an ItemContainer to the Transporter.
     * @param _container The ItemContainer requested to transport.
     * @return true if the ItemContainer has been successfully added to the Transporter. False if the transporter is full, or if is not awaiting orders.
     */
    bool addItemContainer(ItemContainer *_container);

    /**
     * @brief Get the first ItemContainer which carries the specified ItemTypeUUID
     * @param _itemType The specified ItemTypeUUID
     * @return An ItemContainer with the specified ItemTypeUUID if available, nullptr otherwise.
     */
    ItemContainer *getItemContainer(s_ItemTypeUUID _itemType);

    /**
     * @brief Get the first ItemContainer transported.
     * @return An ItemContainer if available, nullptr otherwise.
     */
    ItemContainer *getAnyItemContainer();

    /**
     * @brief Return if the Transporter is full.
     * @return true if full, false otherwise.
     */
    bool isFull();

    /**
     * @brief Return if the Transporter is empty.
     * @return true if empty, false otherwise.
     */
    bool isEmpty();

    /**
     * @brief Request the transporter to move to a next tile (i.e. goes to Moving state).
     * @return true if Transporter was awaiting orders, false otherwise.
     */
    bool moveToNextTile();

    /**
     * @brief Return if the transporter is currently in Loading state.
     * @return true if Transporter is currently loading, false otherwise.
     */
    bool isLoading();

    /**
     * @brief Return if the transporter is currently in awaiting orders.
     * @return true if Transporter is currently waiting/idling, false otherwise.
     */
    bool waitingToMove();

    /**
     * @brief Return if the transporter is currently in Moving state.
     * @return true if Transporter is currently moving, false otherwise.
     */
    bool isMoving();

    /**
     * @brief Return if the transporter is currently in Unloading state.
     * @return true if Transporter is currently unloading, false otherwise.
     */
    bool isUnloading();

    /**
     * @brief Perform actions occurring at a game turn.
     */
    void runTick();

    /**
     * @brief Sets the Graph course to follow
     * @param _course Graph course to follow
     */
    void setGraphCourse(GraphCourse *_course);

    /**
     * @brief Return the next Graph Element to follow
     * @return s_GraphElementUUID next graph element UUID
     */
    s_GraphElementUUID getNextGraphElement();

	/**
	 * @brief Set the followed path as dirty.
	 */
    void setCourseDirty();

    /**
     * @brief Set the current graph element UUID
     */
     void setCurrentGraphElementID(s_GraphElementUUID _uuid);
private:
    TransporterDefinition m_transporterRules; ///< The transporter game rules: i.e. number of turns per action.
    s_NumberofRounds m_remainingTicksCurrentState; ///< The current number of rounds occurred for the current action.
    s_ItemContainerQty m_nbMaxContainers; ///< The maximum number of containers the Transporter can carry.
    s_ItemContainerQty m_CurrentNbContainers; ///< The current number of containers the Transporter carries.

    ObjList<ItemContainer> *mt_Containers; ///< The carried containers.

    enum eTransporterState ///< Internal state machine declaration.
    {
        eTransporterState_Idle,
        eTransporterState_Loading,
        eTransporterState_Awaiting,
        eTransporterState_Moving,
        eTransporterState_Unloading
    };

    eTransporterState m_State; ///< Current state.

    GraphCourse *m_graphCourse;  ///< Current graph course

    ObjListIterator<s_GraphElementUUID> *m_graphIterator;

    s_GraphElementUUID m_currentGraphUUID;
};


#endif //FACTORYBUILDER_TRANSPORTER_H
