/**
 * The CLAYEngine project.
 *
 * @file /src/osal/common/renderer/IRenderer.h
 *
 * @brief The entry point for the system OSAL (init and termination)
 */

/*
 * CHANGELOG:
 * 15/06/2024: File creation (NG)
 */

#ifndef _SRC_OSAL_SDL_RENDERER_RENDERER_H
#define _SRC_OSAL_SDL_RENDERER_RENDERER_H

#include <IRenderer.h>
#include <SDL2/SDL.h>
// #include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_video.h>

class Renderer : public IRenderer
{
public:
    Renderer(SDL_Renderer *_pRenderer);

    ~Renderer();

    SDL_Renderer *getRenderer();

protected:
    SDL_Renderer *m_pRenderer;
};

#endif