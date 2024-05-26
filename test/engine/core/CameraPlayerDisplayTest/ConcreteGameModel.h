/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/ConcreteGameModel.h
 *
 * \brief The controller object of the MVC model.
 */

/*
 * CHANGELOG:
 * 23/03/2024: File creation (NG)
 */

#ifndef _ENGINE_CORE_ConcreteGameModel_H
#define _ENGINE_CORE_ConcreteGameModel_H

#include <Types.h>
#include <ITile.h>
#include <IGameModel.h>

class ConcreteGameModel : public IGameModel
{
public:
	ConcreteGameModel(s_MapWidth _width, s_MapHeight _height);
	~ConcreteGameModel();

private:

};

#endif
