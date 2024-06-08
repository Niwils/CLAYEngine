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
#include <iostream>

OsalSys::OsalSys()
: IOsalSys()
, m_pRenderer(nullptr)
, m_pPlayerWindowSurface(nullptr)
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

void OsalSys::exit()
{
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pPlayerWindow);
	SDL_Quit();
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
		// int imgFlags = IMG_INIT_PNG;
    	// IMG_Init( imgFlags );
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

		m_pRenderer = SDL_CreateRenderer(m_pPlayerWindow, -1, SDL_RENDERER_ACCELERATED);

		SDL_SetRenderDrawColor(m_pRenderer, 96, 128, 255, 255);
		SDL_RenderClear(m_pRenderer);

		SDL_RenderPresent(m_pRenderer);

		m_pPlayerWindowSurface =  SDL_GetWindowSurface(m_pPlayerWindow);

		return 0;
	}

}

s_errorReturn OsalSys::setupBackgroundColor(s_pixel _backgroundColor)
{
	uint8_t l_red, l_green, l_blue, l_alpha;
	l_red = (_backgroundColor>>24U)&0x000000FF;
	l_green = (_backgroundColor>>16U)&0x000000FF;
	l_blue = (_backgroundColor>>8U)&0x000000FF;
	l_alpha = _backgroundColor&0x000000FF;
	SDL_SetRenderDrawColor(m_pRenderer, l_red, l_green, l_blue, l_alpha);

	SDL_RenderClear(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
	return 0;
}

void OsalSys::clearWindow()
{
	SDL_RenderClear( m_pRenderer );
}

void OsalSys::updateWindow()
{
	SDL_RenderPresent(m_pRenderer);
}

SDL_Window *OsalSys::getWindow()
{
	return m_pPlayerWindow;
}

s_Tick OsalSys::getTicksElapsed()
{
	return SDL_GetTicks();
}

ISprite *OsalSys::loadSprite(s_fileName _fileSprite, s_nbPixels _height, s_nbPixels _width, s_nbPixels _length, s_nbFrames _nbFrames, s_coord2d _center)
{
	SDL_Surface *l_pLoadSurface = SDL_LoadBMP(_fileSprite.c_str());
	
	// TODO throw error if loading has failed

	SDL_Texture *l_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, l_pLoadSurface);
	SDL_FreeSurface(l_pLoadSurface);

	ISprite *l_returnSprite = new Sprite(l_pTexture, _height, _width, _length, _nbFrames, _center);

	return l_returnSprite;
}

void OsalSys::displaySprite(ISpriteWindow *_pSprite, s_coord2d _coords, s_zoomRatio _zoomRatio)
{
	SpriteWindow *l_pSpriteWindow = static_cast<SpriteWindow *>(_pSprite);
	Sprite *l_pSprite = static_cast<Sprite *>(l_pSpriteWindow->getSprite());

	SDL_Texture *l_pTexture = l_pSprite->getTexture();

	SDL_Rect l_src = l_pSpriteWindow->getShownSpriteArea();
	SDL_Rect l_dst = l_pSpriteWindow->getDisplayableArea(_coords, _zoomRatio);

	SDL_RenderCopy(m_pRenderer, l_pTexture, &l_src, &l_dst);
}
