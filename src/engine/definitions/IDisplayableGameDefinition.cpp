/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/definitions/IGameDefinition.cpp
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 27/04/2024: File creation (NG)
 */

#include <IDisplayableGameDefinition.h>

IDisplayableGameDefinition::IDisplayableGameDefinition(s_gameElementUUID _uuid, ISprite *_sprite, s_bool _isAnimated, s_bool _isPlayerEditable)
: IGameDefinition(_uuid, _isPlayerEditable)
{
	m_pSprite = _sprite;
	m_isAnimated = _isAnimated;
}

IDisplayableGameDefinition::~IDisplayableGameDefinition()
{

}


ISprite *IDisplayableGameDefinition::getSprite()
{
	return m_pSprite;
}

void IDisplayableGameDefinition::setSprite(ISprite *_sprite)
{
	m_pSprite = _sprite;
}