/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/definitions/IGameDefinition.cpp
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 14/04/2024: File creation (NG)
 */

#include <IGameDefinition.h>

IGameDefinition::IGameDefinition(s_gameElementUUID _uuid, s_bool _isPlayerEditable)
: m_uuid(_uuid)
, m_isPlayerEditable(_isPlayerEditable)
{

}

IGameDefinition::~IGameDefinition()
{

}

s_gameElementUUID IGameDefinition::getUUID()
{
	return m_uuid;
}

s_bool IGameDefinition::isPLayerEditable()
{
	return m_isPlayerEditable;
}
