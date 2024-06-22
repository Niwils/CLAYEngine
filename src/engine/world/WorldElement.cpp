/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/world/WorldElement.h
 *
 * \brief The map the game is currently evolving (i.e. what the player can see)
 * It is a 2D map of ITile objects, which can be a facility floor or pure decoration.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#include <WorldElement.h>

WorldElement::WorldElement(WorldElementDefinition *_def, IRenderer *_pRenderer)
: ITile()
, m_pDef(nullptr)
{
    m_pDef = _def;
    s_coord2d l_coord = {0, 0};

    ISprite *l_pSprite = m_pDef->getSprite();
    m_pSpriteWindow = new SpriteWindow(l_pSprite, _pRenderer,
                                        l_coord,
                                        l_pSprite->getWidth(),
                                        l_pSprite->getHeight()
                                    );
}

WorldElement::~WorldElement()
{

}