/*
 * The <unnamed> factory builder project.
 *
 * \file /src/engine/transportation/TransportationTile.cpp
 *
 * \brief Describe a tile where a Transporter object is allowed to pass by.
 */

/*
 * CHANGELOG:
 * 17/12/2020: File creation (NG)
 */
#include <TransportationTile.h>

TransportationTile::TransportationTile(s_EdgeFifoSize _size)
: IEdge(_size)
{

}

TransportationTile::~TransportationTile()
{
    
}