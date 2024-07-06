/*!
 * The CLAYEngine project.
 *
 * \file /src/core/MenuSpritesContainer.h
 *
 * \brief Container for the menu icons.
 */

/*
 * CHANGELOG:
 * 06/07/2024: File creation (NG)
 */

#include <MenuSpritesContainer.h>

MenuSpritesContainer::MenuSpritesContainer()
{
    m_pHashMap = new HashHeap<eMenuSpritesContainer, ISprite>();
}

MenuSpritesContainer::~MenuSpritesContainer()
{
    // TODO delete icons?
    delete m_pHashMap;
}

void MenuSpritesContainer::addSprite(eMenuSpritesContainer _iconDef, ISprite *_pSprite)
{
    // TODO: check no icondef has already an icon loaded.
    m_pHashMap->addObj(_iconDef, _pSprite);
}

ISprite *MenuSpritesContainer::getSprite(eMenuSpritesContainer _iconDef)
{
    return m_pHashMap->getObj(_iconDef);
}