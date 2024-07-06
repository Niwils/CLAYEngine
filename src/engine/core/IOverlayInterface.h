/*!
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IOverlay.h
 *
 * \brief An abstract class for menu and other overlays implementation.
 */

/*
 * CHANGELOG:
 * 09/06/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_IOVERLAYINTERFACE_H
#define _ENGINE_CORE_IOVERLAYINTERFACE_H

#include <Types.h>
#include <PlayerKeyboardRoute.h>
#include <IRenderer.h>

/*!
 * \brief An abstract interface between menu and other overlays implementation, and the PlayerDisplay.
 */
class IOverlayInterface
{
public:
    /*!
    * \brief The IOverlayInterface constructor (initializes both UUID and IRenderer attributes)
    *
    * \param _uuid The new overlay UUID
    * \param _pRenderer A pointer to the in-game graphic renderer.
    */
    IOverlayInterface(s_uuid _uuid, IRenderer *_pRenderer);

    /*!
    * \brief The IOverlayInterface destructor (strictly does nothing)
    */
    ~IOverlayInterface();

    /*!
    * \brief Returns if the click coordinates are within the displayable area of the overlay.
    *
    * \param _clickCoordinates The player click coordinates (window referential).
    * \return If true, the player has clicked within the overlay area. Hence, the processClick() function shall be called for click processing.
    */
    virtual bool clickWithinOverlay(s_coord2d _clickCoordinates) = 0;

    /*!
    * \brief Process the click coordinates within the displayable area of the overlay.
    *
    * \param _clickCoordinates The player click coordinates (window referential).
    * \return ePlayerKeyboardRoute_Camera if the click has no impact on the route of keyboard keys, ePlayerKeyboardRoute_TextInput if the player has clicked in a form, for example.
    */
    virtual ePlayerKeyboardRoute processClick(s_coord2d _clickCoordinates) = 0;

    /*!
    * \brief Loads the IOverlay content in the associated renderer.
    */
    virtual void draw() = 0;

    /*!
    * \brief Getter for the Overlay UUID
    *
    * \return The overlay UUID.
    */
    s_uuid getUuid();

    /*!
    * \brief Setter for the Overlay UUID
    *
    * \param _uuid The overlay UUID.
    */
    void setUuid(s_uuid _uuid);

protected:
    /*!
    * \brief The Overlay UUID
    */
    s_uuid m_uuid;

    /*!
    * \brief Pointer to the in-game renderer.
    */
    IRenderer *m_pRenderer;
};

#endif /** End of _ENGINE_CORE_IOVERLAYINTERFACE_H */