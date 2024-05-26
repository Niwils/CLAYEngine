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
#include <SpriteWindow.h>
#include <SDL2/SDL.h>
// #include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_video.h>


class OsalSys : public IOsalSys
{
public:
	OsalSys();
	~OsalSys();

	s_errorReturn init();

	void exit();

	s_errorReturn createNewWindow(s_playerWindowWidth _width, s_playerWindowHeight _height);

	s_errorReturn setupBackgroundColor(s_pixel _backgroundColor);

	void clearWindow();

	void updateWindow();

	SDL_Window *getWindow();

	s_Tick getTicksElapsed();

	ISprite *loadSprite(s_fileName _fileSprite, s_nbPixels _height, s_nbPixels _width, s_nbPixels _length, s_nbFrames _nbFrames, s_coord2d _center);

	void displaySprite(ISpriteWindow *_pSprite, s_coord2d _coords, s_zoomRatio _zoomRatio);
protected:

private:
	SDL_Window *m_pPlayerWindow;
	SDL_Renderer *m_pRenderer;

	SDL_Surface *m_pPlayerWindowSurface;

};

#endif /* End _OSAL_SDL_OSALSYS_H */
