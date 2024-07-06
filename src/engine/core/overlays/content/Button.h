/**
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/overlays/content/Button.h
 *
 * \brief The buttons of overlays.
 */

/*
 * CHANGELOG:
 * 15/06/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_OVERLAYS_CONTENT_BUTTON_H
#define _ENGINE_CORE_OVERLAYS_CONTENT_BUTTON_H

#include <Types.h>
#include <Rectangle.h>

class Button
{
public:
    Button(IRenderer *_pRenderer, s_nbPixels _buttonWidth, s_nbPixels _buttonHeight, s_coord2d _buttonPos);
    ~Button();

    void processClick(s_coord2d _clickCoordinates);

    bool clickWithinButton(s_coord2d _clickCoordinates);

    void draw();

protected:

    IRectangle *m_pRectangle;
    
    s_coord2d m_topLeft;
    s_nbPixels m_width;
    s_nbPixels m_height;

};

#endif /** End of _ENGINE_CORE_OVERLAYS_CONTENT_BUTTON_H */