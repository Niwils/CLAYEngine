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
#include <Transporter.h>

TransportationTile::TransportationTile(s_GraphElementUUID _uuid, s_EdgeFifoSize _size)
: IEdge(_uuid, _size)
{

}

TransportationTile::~TransportationTile()
{
    
}

// Note: no need to secure if the FIFO has changed during the same game turn, as Transporters are updated by the scheduler.
IToken *TransportationTile::getToken() {
    IToken *l_ret = nullptr;
    Transporter *l_transporter = dynamic_cast<Transporter *>(m_Fifo->getFirstElement());

    // Move to the end of the FIFO has been done, with the appropriate animation/number of ticks
    if(true == l_transporter->waitingToMove())
    {
        l_ret = m_Fifo->unqueue();
    }
    bool l_fifoMove = false;
    for(s_EdgeFifoSize icpt = (m_FifoSize-1); 0U <= icpt; icpt--)
    {
        l_transporter = dynamic_cast<Transporter *>(m_Fifo->getElementNo(icpt));
        l_fifoMove = false;

        if(true == l_transporter->waitingToMove()) // Transporter is awaiting. Let's move it to the other tile
        {
            l_fifoMove = m_Fifo->moveToNextSlot(icpt); // But first, let's ensure next tile is clear.

            if(true == l_fifoMove)  // Next tile available. Let's move the transporter.
            {
                l_transporter->moveToNextTile();
            }
        }
    }

    if(true == l_fifoMove) // Object in FIFO position zero has moved to position one, position zero is now available
    {
        IToken *l_sourceTransporter = m_Source->getToken(); // Let's ask the source if something is available...

        if(nullptr != l_sourceTransporter)
        {
            m_Fifo->queue(l_sourceTransporter);
        }
    }

    return l_ret;
}