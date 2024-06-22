/*
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

typedef int8_t s_errorReturn;

typedef uint32_t s_Tick;

typedef uint16_t s_EdgeFifoSize;

typedef int16_t s_HashHeapDepth;

typedef uint32_t s_GraphElementUUID;

typedef uint8_t s_ItemVolume; /*< Quantity of Items provided/consumed per (turn? day?) by an IMarketProvider/IMarketConsumer */

typedef uint32_t s_gameElementUUID;

typedef uint16_t s_ProcessNo;
typedef uint32_t s_RecipeUID;
typedef uint8_t s_ItemQuantity; /*< Quantity of Items*/
typedef uint8_t s_ItemContainerQty; /*< Quantity of ItemContainer */

typedef uint8_t s_NumberofRounds; /*< Quantity of game round/game */
typedef uint8_t s_ArrayQtyNumber; /*< Type for array sizes */

typedef uint16_t s_MapWidth;
typedef uint16_t s_MapHeight;

typedef int16_t s_coord;

typedef struct
{
	s_coord x;
	s_coord y;
} s_coord2d;

typedef float s_zoomRatio;

typedef uint16_t s_nbPixels;
typedef uint32_t s_pixel;

typedef uint16_t s_framerate;

typedef uint16_t s_nbFrames;


typedef bool s_Transition;

typedef bool s_bool;

enum ePlayerSettingsDisplayResolution
{
	ePlayerSettingsDisplayResolution_None,
	ePlayerSettingsDisplayResolution_640x480,
	ePlayerSettingsDisplayResolution_1024x768
};

typedef uint32_t s_playerWindowWidth;
typedef uint32_t s_playerWindowHeight;

typedef bool s_isFullscreen;

typedef float s_rotationCoeff;

typedef std::string s_fileName;

typedef uint32_t s_uuid;

#endif /* End _COMMON_TYPES_H */
