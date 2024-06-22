/**
 * The CLAYEngine project.
 *
 * @file /src/osal/common/renderer/IRenderer.h
 *
 * @brief The entry point for the system OSAL (init and termination)
 */

/*
 * CHANGELOG:
 * 19/06/2024: File creation (NG)
 */

#ifndef _SRC_OSAL_COMMON_RENDERER_IRENDERER_H
#define _SRC_OSAL_COMMON_RENDERER_IRENDERER_H

#include <Types.h>

class IRenderer
{
public:
    IRenderer();

    virtual ~IRenderer() = 0;
};

#endif