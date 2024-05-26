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
{
}

IOsalSys::~IOsalSys()
{
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

void IOsalSys::displaySprite(ISpriteWindow *_pSprite, s_coord2d _coords, s_zoomRatio _zoomRatio)
{

}
