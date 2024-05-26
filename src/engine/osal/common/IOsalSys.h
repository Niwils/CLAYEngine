/**
 * The CLAYEngine project.
 *
 * @file /src/osal/sdl/OsalSys.h
 *
 * @brief The entry point for the system OSAL (init and termination)
 */

/*
 * CHANGELOG:
 * 23/03/2024: File creation (NG)
 */

#ifndef _OSAL_COMMON_IOSALSYS_H
#define _OSAL_COMMON_IOSALSYS_H

#include <Types.h>
#include <ISpriteWindow.h>

class IOsalSys
{
public:
	IOsalSys();
	virtual ~IOsalSys() = 0;

	virtual s_errorReturn init() = 0;

	virtual void exit() = 0;

	virtual s_errorReturn createNewWindow(s_playerWindowWidth _width, s_playerWindowHeight _height) = 0;

	virtual s_errorReturn setupBackgroundColor(s_pixel _backgroundColor) = 0;

	virtual void clearWindow() = 0;
	
	virtual void updateWindow() = 0;

	virtual s_Tick getTicksElapsed() = 0;

	virtual void displaySprite(ISpriteWindow *_pSprite, s_coord2d _coords, s_zoomRatio _zoomRatio) = 0;
protected:

private:

};

#endif /* End _OSAL_COMMON_IOSALSYS_H */
