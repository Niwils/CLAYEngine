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

#ifndef _ENGINE_CORE_MENUSPRITESCONTAINER_H
#define _ENGINE_CORE_MENUSPRITESCONTAINER_H

#include <Types.h>
#include <ISprite.h>
#include <HashHeap.h>

enum eMenuSpritesContainer : s_uuid
{
    eMenuSpritesContainer_closeButton,
    eMenuSpritesContainer_settings,
    eMenuSpritesContainer_build,
    eMenuSpritesContainer_build_manufacturing
};

/*!
* \brief A MenuSpritesContainer is a container storing the icons for the different menus within the User Interface.
*/
class MenuSpritesContainer
{
public:
    /*!
    * \brief Contructor for the MenuSpritesContainer
    */
   MenuSpritesContainer();

   /*!
    * \brief Desctructor for the MenuSpritesContainer
    */
   ~MenuSpritesContainer();

    /*!
    * \brief Adds the icon (sprite) for a given icon identifier.
    * \param _iconDef The icon identifier, defined by eMenuSpritesContainer
    * \param _pSprite The new icon sprite.
    */
   void addSprite(eMenuSpritesContainer _iconDef, ISprite *_pSprite);

    /*!
    * \brief Returns the icon (sprite) for a given icon identifier.
    * \param _iconDef The icon identifier, defined by eMenuSpritesContainer
    * \return The sprite associated with the given icon definition. Can be nullptr if no icon has been loaded.
    */
   ISprite *getSprite(eMenuSpritesContainer _iconDef);

private:
    /*!
    * \brief Container for the icon sprites vs the icon definition.
    */
    HashHeap<eMenuSpritesContainer, ISprite> *m_pHashMap;
};

#endif /*< End of _ENGINE_CORE_MENUSPRITESCONTAINER_H */