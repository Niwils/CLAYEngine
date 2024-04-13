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

#include <IGameModel.h>

IGameModel::IGameModel(s_MapWidth _width, ::s_MapHeight _height)
{

};

IGameModel::~IGameModel()
{
};

ITile **IGameModel::getTiles()
{
	return m_vTiles;
};

ITile *IGameModel::getTile(s_coord2d _coord2d)
{
	return &(m_vTiles[_coord2d.y][_coord2d.x]);
};

s_errorReturn IGameModel::setTile(s_coord2d _coord2d, ITile *_pTile)
{
	/*if (nullptr != m_vTiles[_coord2d.y][_coord2d.x])
	{
		delete &(m_vTiles[_coord2d.y][_coord2d.x]);
	}

	&(m_vTiles[_coord2d.y][_coord2d.x]) = _pTile;*/
};

s_MapWidth IGameModel::getMapWidth()
{
 return m_mapWidth;
}

s_MapHeight IGameModel::getMapHeight()
{
 return m_mapHeight;
}
