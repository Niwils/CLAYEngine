/**
 * The CLAYEngine project.
 *
 * @file /src/osal/common/renderer/IRenderer.cpp
 *
 * @brief The entry point for the system OSAL (init and termination)
 */

/*
 * CHANGELOG:
 * 19/06/2024: File creation (NG)
 */

#include <Renderer.h>

Renderer::Renderer(SDL_Renderer *_pRenderer)
: IRenderer()
, m_pRenderer(nullptr)
{
    m_pRenderer = _pRenderer;
}

Renderer::~Renderer()
{
    
}

SDL_Renderer *Renderer::getRenderer()
{
    return m_pRenderer;
}