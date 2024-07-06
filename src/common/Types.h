/*!
 * The <unnamed> factory builder project.
 *
 * \file src/common/Types.h
 *
 * \brief Common Types used by the game
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */

#ifndef _COMMON_TYPES_H
#define _COMMON_TYPES_H

#include <stdint.h>
#include <string>

typedef int8_t s_errorReturn; /*!< Type for error code */

typedef uint32_t s_Tick; /*!< Type for ticks */

typedef uint16_t s_EdgeFifoSize;

typedef int16_t s_HashHeapDepth; /*!< Type for hash heap depth */

typedef uint32_t s_GraphElementUUID; /*!< Type for graph element UUID */

typedef uint8_t s_ItemVolume; /*!< Quantity of Items provided/consumed per (turn? day?) by an IMarketProvider/IMarketConsumer */

typedef uint32_t s_gameElementUUID; /*!< Type for game element UUID */

typedef uint16_t s_ProcessNo; /*!< Type for process no */
typedef uint32_t s_RecipeUID; /*!< Type for recipe UID */
typedef uint8_t s_ItemQuantity; /*!< Quantity of Items */
typedef uint8_t s_ItemContainerQty; /*!< Quantity of ItemContainer */

typedef uint8_t s_NumberofRounds; /*!< Quantity of game round/game */
typedef uint8_t s_ArrayQtyNumber; /*!< Type for array sizes */

typedef uint16_t s_MapWidth; /*!< Type for map width */
typedef uint16_t s_MapHeight; /*!< Type for map height */

typedef int16_t s_coord; /*!< Type for single-dimension coordinates */

typedef struct	/*!< Type for 2D coordinates */
{
	s_coord x;
	s_coord y;
} s_coord2d;

typedef float s_zoomRatio; /*!< Type for zoom ratio */

typedef uint16_t s_nbPixels; /*!< Type for number of pixels */
typedef uint32_t s_pixel; /*!< Type for pixel value (content) */

typedef uint16_t s_framerate; /*!< Type for frame rate */

typedef uint16_t s_nbFrames; /*!< Type for number of frames */


typedef bool s_Transition; /*!< Type for transition state (true or false) */

typedef bool s_bool; /*!< Type for boolean */

enum ePlayerSettingsDisplayResolution /*!< Type for player window resolution */
{
	ePlayerSettingsDisplayResolution_None, /*!< No display resolution */
	ePlayerSettingsDisplayResolution_640x480, /*!< 640x480 resolution */
	ePlayerSettingsDisplayResolution_1024x768 /*!< 1024x768 resolution */
};

typedef uint32_t s_playerWindowWidth; /*!< Type for player window width */
typedef uint32_t s_playerWindowHeight; /*!< Type for player window height */

typedef bool s_isFullscreen; /*!< Type for fullscreen */

typedef float s_rotationCoeff; /*!< Type for rotation coefficient */

typedef std::string s_fileName; /*!< Type for file name */

typedef uint32_t s_uuid; /*!< Type for UUID */

#endif /* End _COMMON_TYPES_H */
