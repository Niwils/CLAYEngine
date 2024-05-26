/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/core/IGameModel.h
 *
 * \brief The controller object of the MVC model.
 */

/*
 * CHANGELOG:
 * 23/03/2024: File creation (NG)
 */

#include "ConcreteGameModel.h"

ConcreteGameModel::ConcreteGameModel(s_MapWidth _width, s_MapHeight _height)
: IGameModel(_width, _height)
{

};

ConcreteGameModel::~ConcreteGameModel()
{
};

