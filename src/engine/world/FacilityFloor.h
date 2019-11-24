/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/world/FacilityFloor.h
 *
 * \brief A factory facility tile of the World 2D map.
 * It is the default tile when a factory is just made.
 * Note: ContainerCarrier objects have the ability to use these tiles as roads.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */
#include <IFacilityTile.h>
#include <IEdge.h>
#include <ContainerCarrier.h>

class FacilityFloor : public IFacilityTile, IEdge
{
public:
	FacilityFloor();
	~FacilityFloor();

	void setContainerCarrier(ContainerCarrier *_carrier);
	ContainerCarrier *getContainerCarrier();


private:
	// Currently, only one carrier is allowed on a tile.
	ContainerCarrier *m_Carrier;
};
