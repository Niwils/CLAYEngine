/*!
 * The <unnamed> factory builder project.
 *
 * \file src/common/GeographyDefinitions.h
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

/*!
* \brief Indexes giving the geographical definition of a tile.
*/
enum eGeographyDefinition : uint8_t
{
	eGeographyDefinition_North = 0, /*!< Index for the north */
	eGeographyDefinition_East = 1, /*!< Index for the east */
	eGeographyDefinition_South = 2, /*!< Index for the south */
	eGeographyDefinition_West = 3, /*!< Index for the west */
	eGeographyDefinition_Max = 4 /*!< Maximum enumeration value */
};

/*!
* \brief Indexes giving the geographical definition of the camera orientation.
*/
enum eCameraOrientationDefinition : uint8_t
{
	eCameraOrientationDefinition_NorthWest = 0, /*!< Index for the north-west */
	eCameraOrientationDefinition_NorthEast = 1, /*!< Index for the north-east */
	eCameraOrientationDefinition_SouthWest = 2, /*!< Index for the south-west */
	eCameraOrientationDefinition_SouthEast = 3, /*!< Index for the south-east */
	eCameraOrientationDefinition_Max = 4 /*!< Maximum enumeration value */
};

#endif /* End _COMMON_GEOGRAPHYDEFINITIONS_H */
