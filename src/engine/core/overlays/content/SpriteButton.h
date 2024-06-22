/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/overlays/content/SpriteButton.h
 *
 * \brief The buttons of overlays.
 */

/*
 * CHANGELOG:
 * 16/06/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_OVERLAYS_CONTENT_SPRITEBUTTON_H
#define _ENGINE_CORE_OVERLAYS_CONTENT_SPRITEBUTTON_H

#include <Types.h>
#include <Button.h>
#include <SpriteWindow.h>

class SpriteButton : public Button
{
public:
    SpriteButton(IRenderer *_pRenderer, ISprite *_pSprite, s_nbPixels _buttonWidth, s_nbPixels _buttonHeight, s_coord2d _buttonPos, s_pixel _bgColour);
    ~SpriteButton();

    void processClick(s_coord2d _clickCoordinates);

    bool clickWithinButton(s_coord2d _clickCoordinates);

    void draw();

protected:
    s_coord2d m_spritePosition;
    s_zoomRatio m_spriteRatio;
    ISpriteWindow *m_pSprite;
};

#endif /** End of _ENGINE_CORE_OVERLAYS_CONTENT_SPRITEBUTTON_H */