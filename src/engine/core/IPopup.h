/*!
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IPopup.h
 *
 * \brief An abstract class for menu and other overlays implementation.
 */

/*
 * CHANGELOG:
 * 09/06/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_IPOPUP_H
#define _ENGINE_CORE_IPOPUP_H

#include <Types.h>
#include <PlayerKeyboardRoute.h>
#include <IOverlay.h>
#include <ObjList.h>
#include <SpriteButton.h>
#include <MenuSpritesContainer.h>

/*!
* \brief An IPopup is an (abstract) overlay that is opened next to a click. It can be closed by the user by pressing the upper right close button.
*/
class IPopup : public IOverlay
{
public:
    /*!
    * \brief IPopup constructor
    *
    * \param _uuid The overlay UUID
    * \param _pRenderer Pointer to the graphical renderer.
    * \param _pSprites Pointer to the menu sprites container.
    * \param _overlayWidth The overlay width
    * \param _overlayHeight The overlay height
    * \param _overlayTopLeftPos The top left position of the overlay (window referential)
    * \param _pDisplay Pointer to the IPlayerDisplayInterface
    */
    IPopup(s_uuid _uuid, IRenderer *_pRenderer, MenuSpritesContainer *_pSprites, s_nbPixels _overlayWidth, s_nbPixels _overlayHeight, s_coord2d _overlayTopLeftPos, IPlayerDisplayInterface *_pDisplay);
    
    /*!
    * \brief Destructor for the IPopup
    */
    ~IPopup();

    /*!
    * \brief Return true if the click is within the overlay coordinates.
    * \param _clickCoordinates The click coordinates (Window referential)
    * \return True if click coordinates are within the overlay coordinates, false otherwise.
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
    * \brief Pointer to the menu icons container.
    */
    MenuSpritesContainer *m_pSprites;

    /*!
    * \brief Pointer to the popup close button.
    */
    SpriteButton *m_pCloseButton;

    /*!
    * \brief Pointer to the top bar rectangle.
    */
    IRectangle *m_pTopBar;
};

#endif /** End of _ENGINE_CORE_IPOPUP_H */