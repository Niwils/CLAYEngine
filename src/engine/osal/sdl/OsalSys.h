/**
 * The CLAYEngine project.
 *
 * @file /src/osal/sdl/OsalSys.h
 *
 * @brief The entry point for the system OSAL (init and termination)
 */

/*
 * CHANGELOG:
 * 17/03/2024: File creation (NG)
 */

#ifndef _OSAL_SDL_OSALSYS_H
#define _OSAL_SDL_OSALSYS_H

#include <Types.h>
#include <IOsalSys.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>


class OsalSys : public IOsalSys
{
public:
	OsalSys();
	~OsalSys();

	s_errorReturn init();

	s_errorReturn stop();

	s_errorReturn createNewWindow(s_playerWindowWidth _width, s_playerWindowHeight _height);

	SDL_Window *getWindow();

	s_Tick getTicksElapsed();

	//void displaySprite(Sprite *_pSprite, s_coord2d _coords, s_pixelsPerTile _renderingSize);
protected:

private:
	SDL_Window *m_pPlayerWindow;
	SDL_Renderer *m_pRenderer;

};

#endif /* End _OSAL_SDL_OSALSYS_H */
