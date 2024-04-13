/**
 * The CLAYEngine project.
 *
 * @file /src/engine/osal/sdl/OsalSys.h
 *
 * @brief The SDL wrapper entry-point.
 *
 */

/*
 * CHANGELOG:
 * 17/03/2024: File creation (NG)
 */

#include <OsalSys.h>

OsalSys::OsalSys()
: IOsalSys()
, m_pRenderer(nullptr)
{
}

OsalSys::~OsalSys()
{

}

s_errorReturn OsalSys::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

s_errorReturn OsalSys::stop()
{
	return -1;
}

s_errorReturn OsalSys::createNewWindow(s_playerWindowWidth _width, s_playerWindowHeight _height)
{
	// TODO: assert init has been done

	// TODO manage fullscreen and other player settings.
	// TODO manage window title
	m_pPlayerWindow = SDL_CreateWindow("CLAYEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);

	if (!m_pPlayerWindow)
	{
		return -1;
	}
	else
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

		m_pRenderer = SDL_CreateRenderer(m_pPlayerWindow, -1, SDL_RENDERER_ACCELERATED);

		SDL_SetRenderDrawColor(m_pRenderer, 96, 128, 255, 255);
		SDL_RenderClear(m_pRenderer);

		SDL_RenderPresent(m_pRenderer);

		return 0;
	}

}

SDL_Window *OsalSys::getWindow()
{
	return m_pPlayerWindow;
}

s_Tick OsalSys::getTicksElapsed()
{
	return SDL_GetTicks();
}

/*void OsalSys::displaySprite(Sprite *_pSprite, s_coord2d _coords, s_pixelsPerTile _renderingSize)
{
	// TODO
}*/
