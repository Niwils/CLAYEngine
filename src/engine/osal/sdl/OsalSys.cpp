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
, Renderer(nullptr)
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

void OsalSys::getAndParseEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT)
		{
			m_windowCloseRequested = true;
		}
		if (e.type == SDL_KEYDOWN)
		{
			this->processSDLKey(&e);
		}
		if ((e.type == SDL_MOUSEBUTTONDOWN)
			|| (e.type == SDL_MOUSEMOTION)
			|| (e.type == SDL_MOUSEWHEEL)){
			this->processSDLMouse(&e);
		}
	}
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

void OsalSys::processSDLKey(SDL_Event *_event)
{
	switch (_event->key.keysym.sym)
	{
		case SDLK_UP:
		{
			KeyboardEvent *l_key = new KeyboardEvent(eKeyboardKeys_upkey);
			m_keyboardEvents->push_back(l_key);
			break;
		}

		case SDLK_DOWN:
		{
			KeyboardEvent *l_key = new KeyboardEvent(eKeyboardKeys_downkey);
			m_keyboardEvents->push_back(l_key);
			break;
		}
		case SDLK_LEFT:
		{
			KeyboardEvent *l_key = new KeyboardEvent(eKeyboardKeys_leftkey);
			m_keyboardEvents->push_back(l_key);
			break;
		}

		case SDLK_RIGHT:
		{
			KeyboardEvent *l_key = new KeyboardEvent(eKeyboardKeys_rightkey);
			m_keyboardEvents->push_back(l_key);
			break;
		}

		default:
			// Returns nothing.
			break;
	};
}

void OsalSys::processSDLMouse(SDL_Event *_event)
{
	switch(_event->type)
	{
		case SDL_MOUSEMOTION:
		{
			s_coord2d l_coords;
			l_coords.x = static_cast<s_coord>(_event->motion.x);
			l_coords.y = static_cast<s_coord>(_event->motion.y);

			MouseEvent *l_event = new MouseEvent(l_coords, eMouseKeys_None);
			m_mouseEvents->push_back(l_event);
			break;
		}

		// TODO handle all the mouse buttons
		case SDL_MOUSEBUTTONDOWN:
		{
			s_coord2d l_coords;
			l_coords.x = static_cast<s_coord>(_event->motion.x);
			l_coords.y = static_cast<s_coord>(_event->motion.y);

			MouseEvent *l_event = new MouseEvent(l_coords, eMouseKeys_LeftClick);
			m_mouseEvents->push_back(l_event);
			break;
		}
		case SDL_MOUSEWHEEL:
		{	
			s_coord2d l_coords;
			l_coords.x = static_cast<s_coord>(_event->motion.x);
			l_coords.y = static_cast<s_coord>(_event->motion.y);

			eMouseKeys l_key;
			if(0 < _event->wheel.y)
			{
				l_key = eMouseKeys_WheelUp;
			}
			else
			{
				l_key = eMouseKeys_WheelDown;
			}

			MouseEvent *l_event = new MouseEvent(l_coords, l_key);
			m_mouseEvents->push_back(l_event);
			break;
		}
	};	
}

SDL_Renderer *OsalSys::getRenderer()
{
	return m_pRenderer;
}