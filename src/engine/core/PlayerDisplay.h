/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/PlayerDisplay.h
 *
 * \brief The view object of the MVC model.
 */

/*
 * CHANGELOG:
 * 16/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_PLAYERDISPLAY_H
#define _ENGINE_CORE_PLAYERDISPLAY_H

#include <Company.h>
#include <IDisplay.h>

class PlayerDisplay : public IDisplay
{
public:
	PlayerDisplay();
	~PlayerDisplay();

	void update();
	void run();

private:
	void parseEvent();
	void parseWindowEvent();
	void changePlayerFOV();

	// Model: The player's company.
	Company *m_playerCompany;

	// Controller: The game controller.
	// TODO

};

#endif /* End _ENGINE_CORE_PLAYERDISPLAY_H */
