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

typedef uint32_t s_Tick;

typedef uint16_t s_EdgeFifoSize;

typedef uint16_t s_HashHeapDepth;

typedef uint32_t s_GraphElementUUID;

typedef uint8_t s_ItemVolume; /*< Quantity of Items provided/consumed per (turn? day?) by an IMarketProvider/IMarketConsumer */

typedef uint32_t s_ItemTypeUUID;

typedef uint32_t s_ProcessUID;
typedef uint16_t s_ProcessNo;
typedef uint32_t s_RecipeUID;
typedef uint8_t s_ItemQuantity; /*< Quantity of Items*/
typedef uint8_t s_ItemContainerQty; /*< Quantity of ItemContainer */

typedef uint8_t s_NumberofRounds; /*< Quantity of game round/game */
typedef uint8_t s_ArrayQtyNumber; /*< Type for array sizes */


typedef bool s_Transition;

#endif /* End _COMMON_TYPES_H */
