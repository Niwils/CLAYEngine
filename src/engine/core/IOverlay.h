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

#ifndef _ENGINE_CORE_IOVERLAY_H
#define _ENGINE_CORE_IOVERLAY_H

#include <Types.h>
#include <PlayerKeyboardRoute.h>
#include <IOverlayInterface.h>
#include <IPlayerDisplayInterface.h>
#include <Rectangle.h>

/*!
* \brief An abstract class for the implementation of overlays
* This class can receive player inputs from the functions from the IOverlayInterface, while it can create new overlays or delete itself or others via
* the associated IPlayerDisplayInterface.
*/
class IOverlay : public IOverlayInterface
{
public:
    /*!
    * \brief IOverlay constructor.
    *
    * \param _uuid The overlay UUID
    * \param _pRenderer Pointer to the graphical renderer
    * \param _overlayWidth The overlay width
    * \param _overlayHeight The overlay height
    * \param _overlayTopLeftPos The top left coordinates of the overlay, within the Window referential
    * \param _pDisplay Pointer to the IPlayerDisplayInterface
    */
    IOverlay(s_uuid _uuid, IRenderer *_pRenderer, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay);
    
    /*!
    * \brief IOverlay destructor.
    */
    ~IOverlay();

    /*!
    * \brief Returns true if the click coordinates (Window referential) are within the overlay.
    *
    * \param _clickCoordinates Player click coordinates
    * \return True if the click is within the overlay, false otherwise.
    */
    bool clickWithinOverlay(s_coord2d _clickCoordinates);

    /*!
    * \brief Proceed the click coordinates (Window referential) (implementation dependent).
    *
    * \param _clickCoordinates Player click coordinates
    * \return The route the keyboard inputs shall follow, if the click has been done in a text area.
    */
    virtual ePlayerKeyboardRoute processClick(s_coord2d _clickCoordinates) = 0;

    /*!
    * \brief When called, draw the overlay in the renderer.
    */
    void draw();

protected:
    /*!
    * \brief Pointer to the IPlayerDisplayInterface
    */
    IPlayerDisplayInterface *m_pDisplay;

    /*!
    * \brief The overlay width
    */
    s_nbPixels m_overlayWidth;

    /*!
    * \brief The overlay height
    */
    s_nbPixels m_overlayHeight;

    /*!
    * \brief The overlay top left coordinates (Window referential)
    */
    s_coord2d m_overlayTopLeftPos;

    /*!
    * \brief The overlay background
    */
    IRectangle *m_pBackground;
};

#endif