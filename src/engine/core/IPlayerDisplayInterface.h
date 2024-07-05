/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IPlayerDisplayInterface.h
 *
 * \brief The interface between an IOverlay and the PlayerDisplay.
 */

/*
 * CHANGELOG:
 * 09/06/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_IPLAYERDISPLAYINTERFACE_H
#define _ENGINE_CORE_IPLAYERDISPLAYINTERFACE_H

#include <Types.h>
#include <IOverlayInterface.h>

/*!
* \brief An IPlayerDisplayInterface is an abstract interface allowing any IOverlay to add or close another IOverlay (or itself) to the PlayerDisplay.
*/
class IPlayerDisplayInterface
{
public:
    /*!
    * \brief The IPlayerDisplayInterface constructor (strictly does nothing)
    */
    IPlayerDisplayInterface();

    /*!
    * \brief The IPlayerDisplayInterface destructor (strictly does nothing too)
    */
    ~IPlayerDisplayInterface();

    /*!
    * \brief Links a new IOverlay to the PlayerDisplay, for rendering.
    * Note: the new IOverlay UUID is determined by the PlayeDisplayInterface itself.
    *
    *  \param _pDisplay Pointer to the new IOverlay.
    */
    virtual void createOverlay(IOverlayInterface *_pDisplay) = 0;

    /*!
    * \brief Request the removal of a given overlay from the PlayerDisplay (can be from the concerned IOverlay itself)
    *
    *  \param _uuid The IOverlay UUID.
    */
    virtual void removeOverlay(s_uuid _uuid) = 0;

    /*!
    * \brief Getter for a new overlay UUID
    *
    * \return The new overlay UUID
    */
   virtual s_uuid getNewOverlayUuid() = 0;
};

#endif /** End of _ENGINE_CORE_IPLAYERDISPLAYINTERFACE_H */