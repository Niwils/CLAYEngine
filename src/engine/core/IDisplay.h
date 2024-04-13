/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IDisplay.h
 *
 * \brief An abstract object called by the controller, to update the player view.
 */

/*
 * CHANGELOG:
 * 16/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_IDISPLAY_H
#define _ENGINE_CORE_IDISPLAY_H

class IDisplay
{
public:
	IDisplay()
	{

	}

	virtual ~IDisplay() = 0;

	virtual void update() = 0;


private:

};

#endif /* End _ENGINE_CORE_IDISPLAY_H */
