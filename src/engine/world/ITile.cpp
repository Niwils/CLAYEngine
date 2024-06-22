#include <ITile.h>

ITile::ITile()
: m_pSpriteWindow(nullptr)
{
    
}

ITile::~ITile()
{

}

ISpriteWindow *ITile::getSpriteWindow()
{
    return m_pSpriteWindow;
}