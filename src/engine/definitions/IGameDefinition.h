/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/definitions/IGameDefinition.h
 *
 * \brief IGameDefinition is an abstract class used by the
 */

/*
 * CHANGELOG:
 * 14/04/2024: File creation (NG)
 */

#ifndef SRC_ENGINE_DEFINITIONS_IGAMEDEFINITION_H_
#define SRC_ENGINE_DEFINITIONS_IGAMEDEFINITION_H_

#include <Types.h>


class IGameDefinition
{
public:
	IGameDefinition(s_gameElementUUID _uuid, s_bool _isPlayerEditable);

	virtual ~IGameDefinition() = 0;

	s_gameElementUUID getUUID();

	s_bool isPLayerEditable();

protected:
	s_gameElementUUID m_uuid; // Definition UUID

	s_bool m_isPlayerEditable;		/*!< If true, allow the player to change the game element
								E.g: a factory wwall is not editable, whilst a basic floor tile is. */

};


#endif /* SRC_ENGINE_DEFINITIONS_IGAMEDEFINITION_H_ */
