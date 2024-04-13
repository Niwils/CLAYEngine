/*
 * The <unnamed> factory builder project.
 *
 * \file src/common/Types.h
 *
 * \brief Common definitions for in-game geographics (maps, neighbours...)
 */

/*
 * CHANGELOG:
 * 24/11/2019: File creation (NG)
 */
#ifndef _COMMON_GEOGRAPHYDEFINITIONS_H
#define _COMMON_GEOGRAPHYDEFINITIONS_H

#include <stdint.h>

enum eGeographyDefinition : uint8_t
{
	eGeographyDefinition_North = 0,
	eGeographyDefinition_East = 1,
	eGeographyDefinition_South = 2,
	eGeographyDefinition_West = 3,
	eGeographyDefinition_Max = 4
};

// Orientation indicates where the camera points to (top left of the Player display)
enum eCameraOrientationDefinition : uint8_t
{
	eCameraOrientationDefinition_NorthWest = 0,
	eCameraOrientationDefinition_NorthEast = 1,
	eCameraOrientationDefinition_SouthWest = 2,
	eCameraOrientationDefinition_SouthEast = 3,
	eCameraOrientationDefinition_Max = 4
};

#endif /* End _COMMON_GEOGRAPHYDEFINITIONS_H */
