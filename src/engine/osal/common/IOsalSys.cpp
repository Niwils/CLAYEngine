/**
 * The CLAYEngine project.
 *
 * @file /src/osal/sdl/OsalSys.cpp
 *
 * @brief The entry point for the system OSAL (init and termination)
 */

/*
 * CHANGELOG:
 * 23/03/2024: File creation (NG)
 */

#include <IOsalSys.h>

IOsalSys::IOsalSys()
: m_keyboardEvents(nullptr)
, m_mouseEvents(nullptr)
, m_windowCloseRequested(false)
{
	m_keyboardEvents = new std::vector<KeyboardEvent *>();
	m_mouseEvents = new std::vector<MouseEvent *>();
}

IOsalSys::~IOsalSys()
{
	this->flushEvents();
	delete m_keyboardEvents;
	delete m_mouseEvents;
}

s_errorReturn IOsalSys::init()
{
	return 0;
}

void IOsalSys::exit()
{

}

s_errorReturn IOsalSys::createNewWindow(s_playerWindowWidth _width, s_playerWindowHeight _height)
{
	return 0;
}

s_errorReturn IOsalSys::setupBackgroundColor(s_pixel _backgroundColor)
{
	return 0;
}

void IOsalSys::clearWindow()
{
	
}

void IOsalSys::updateWindow()
{
	
}

s_Tick IOsalSys::getTicksElapsed()
{
	return 0;
}

ISprite *IOsalSys::loadSprite(s_fileName _fileSprite, s_nbPixels _height, s_nbPixels _width, s_nbPixels _length, s_nbFrames _nbFrames, s_coord2d _center)
{
	return nullptr;
}

void IOsalSys::getAndParseEvents()
{
	// Do nothing, as purely virtual.
}

void IOsalSys::flushEvents()
{
	std::vector<KeyboardEvent *>::iterator l_it = m_keyboardEvents->begin();

	while(l_it != m_keyboardEvents->end())
	{
		m_keyboardEvents->erase(l_it);
	}

	std::vector<MouseEvent *>::iterator l_mouseIt = m_mouseEvents->begin();

	while(l_mouseIt != m_mouseEvents->end())
	{
		m_mouseEvents->erase(l_mouseIt);
	}
}

std::vector<KeyboardEvent *> *IOsalSys::getKeyboardEvents()
{
	return m_keyboardEvents;
}

std::vector<MouseEvent *> *IOsalSys::getMouseEvents()
{
	return m_mouseEvents;
}

bool IOsalSys::isWindowCloseRequested()
{
	return m_windowCloseRequested;
}

void IOsalSys::displaySprite(ISpriteWindow *_pSprite, s_coord2d _coords, s_zoomRatio _zoomRatio)
{

}
