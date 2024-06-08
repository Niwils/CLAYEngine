/**
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

/**
 * \brief This is the abstract class for the Game Model (floor tiles, manufacturing machine, conveyors and their respective contents)
*/
class IGameModel
{
public:
	/**
	* \brief The constructor 
	* \param _width THe map width, in tiles.
	* \param _height The map height, in tiles.
	*/
	IGameModel(s_MapWidth _width, s_MapHeight _height);
	virtual ~IGameModel() = 0;

	/**
	* \brief getter of Tiles vector.
	* \return 1D vector of tiles. Array is organized by y*<map width>+x 
	*/
	std::vector<ITile*> *getTiles();

	/**
	* \brief getter of an ITile, for a given set of coordinates.
	* \param _coord2d 2D coordinates of the requested ITile.
	* \return The ITile at _coord2d coordinates.
	*/
	ITile *getTile(s_coord2d _coord2d);

	/**
	* \brief sets an ITile to the map array.
	* \param _coord2d 2D coordinates for the new tile.
	* \param _pTile pointer to the ITile that must be set.
	* \param TODO. 0 otherwise.
	*/
	s_errorReturn setTile(s_coord2d _coord2d, ITile *_pTile);

	/**
	* \brief Returns the map width, in number of tiles.
	* \return The map width, in number of tiles. 
	*/
	s_MapWidth getMapWidth();

	/**
	* \brief Returns the map height, in number of tiles.
	* \return The map height, in number of tiles. 
	*/
	s_MapHeight getMapHeight();

private:
	std::vector<ITile*> *m_vTiles; /**< Vector containing the tiles, as a 1D array */

	s_MapWidth m_mapWidth; /**< The map width, in number of tiles. */
	s_MapHeight m_mapHeight; /**< The map height, in number of tiles. */
};

#endif
