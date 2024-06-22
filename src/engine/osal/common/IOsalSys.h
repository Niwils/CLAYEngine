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
#include <KeyboardEvent.h>
#include <MouseEvent.h>

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

	virtual ISprite *loadSprite(s_fileName _fileSprite, s_nbPixels _height, s_nbPixels _width, s_nbPixels _length, s_nbFrames _nbFrames, s_coord2d _center) = 0;

	virtual void getAndParseEvents() = 0;

	void flushEvents();

	std::vector<KeyboardEvent *> *getKeyboardEvents();

	std::vector<MouseEvent *> *getMouseEvents();

	bool isWindowCloseRequested();

	virtual void displaySprite(ISpriteWindow *_pSprite, s_coord2d _coords, s_zoomRatio _zoomRatio) = 0;

protected:

		std::vector<KeyboardEvent *> *m_keyboardEvents;

		std::vector<MouseEvent *> *m_mouseEvents;

		bool m_windowCloseRequested;

};

#endif /* End _OSAL_COMMON_IOSALSYS_H */
