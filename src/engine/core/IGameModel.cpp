/*!
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

IGameModel::IGameModel(s_MapWidth _width, s_MapHeight _height)
: m_mapWidth(_width)
, m_mapHeight(_height)
{
	m_vTiles = new std::vector<ITile*>(m_mapHeight*m_mapWidth);
};

IGameModel::~IGameModel()
{
	delete m_vTiles;
};

std::vector<ITile*> *IGameModel::getTiles()
{
	return m_vTiles;
};

ITile *IGameModel::getTile(s_coord2d _coord2d)
{
	// TODO check _coord2d does not go out of map.
	return m_vTiles->at(_coord2d.y*m_mapWidth+_coord2d.x);
};

s_errorReturn IGameModel::setTile(s_coord2d _coord2d, ITile *_pTile)
{
	ITile *l_pTile = m_vTiles->at(_coord2d.y*m_mapWidth+_coord2d.x);

	m_vTiles->at(_coord2d.y*m_mapWidth+_coord2d.x) = _pTile;

	if (nullptr != l_pTile)
	{
		delete l_pTile;
	}
};

s_MapWidth IGameModel::getMapWidth()
{
 return m_mapWidth;
}

s_MapHeight IGameModel::getMapHeight()
{
 return m_mapHeight;
}
