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

#ifndef _ENGINE_CORE_IGAMEMODEL_H
#define _ENGINE_CORE_IGAMEMODEL_H

#include <Types.h>
#include <ITile.h>
#include <iostream>
#include <vector>

class IGameModel
{
public:
	IGameModel(s_MapWidth _width, s_MapHeight _height);
	virtual ~IGameModel() = 0;

	std::vector<ITile*> *getTiles();

	ITile *getTile(s_coord2d _coord2d);

	s_errorReturn setTile(s_coord2d _coord2d, ITile *_pTile);

	s_MapWidth getMapWidth();

	s_MapHeight getMapHeight();

private:
	std::vector<ITile*> *m_vTiles;

	s_MapWidth m_mapWidth;
	s_MapHeight m_mapHeight;
};

#endif
