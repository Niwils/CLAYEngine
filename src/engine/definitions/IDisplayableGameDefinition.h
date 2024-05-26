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

#ifndef SRC_ENGINE_DEFINITIONS_IDISPLAYABLEGAMEDEFINITION_H_
#define SRC_ENGINE_DEFINITIONS_IDISPLAYABLEGAMEDEFINITION_H_

#include <Types.h>
#include <IGameDefinition.h>
#include <ISprite.h>


class IDisplayableGameDefinition : public IGameDefinition
{
public:
	IDisplayableGameDefinition(s_gameElementUUID _uuid, ISprite *_sprite, s_bool _isAnimated, s_bool _isPlayerEditable);

	virtual ~IDisplayableGameDefinition() = 0;

	ISprite *getSprite();

	void setSprite(ISprite *_sprite);

protected:
	ISprite *m_pSprite;			/*!< Pointer to the WorldElementDefinition sprite. */

	s_bool m_isAnimated;		/*!< If true, indicates the sprite is animated. */

};


#endif /* SRC_ENGINE_DEFINITIONS_IDISPLAYABLEGAMEDEFINITION_H_ */
