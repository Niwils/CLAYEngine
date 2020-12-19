/*
 * The <unnamed> factory builder project.
 *
 * \file /src/engine/transportation/TransportationTile.h
 *
 * \brief Describe a tile where a Transporter object is allowed to pass by.
 */

/*
 * CHANGELOG:
 * 17/12/2020: File creation (NG)
 */

#ifndef FACTORYBUILDER_TRANSPORTATIONTILE_H
#define FACTORYBUILDER_TRANSPORTATIONTILE_H

#include <IEdge.h>

class TransportationTile : public IEdge
{
public:
    TransportationTile(s_EdgeFifoSize _size);
    ~TransportationTile();


};

#endif //FACTORYBUILDER_TRANSPORTATIONTILE_H
