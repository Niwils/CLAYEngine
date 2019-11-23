/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/graph/IEdge.h
 *
 * \brief An IEdge object a n-step FIFO allowing ITokens objects to transit
 * 			between two INode objects. An IEdge can be seen as a conveyor belt,
 * 			or any transportation system.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */
#include <stdint.h>
#include <IToken.h>

class IEdge
{
public:
	IEdge();
	virtual ~IEdge() = 0;

	uint8_t addToken(IToken *_token);
	uint8_t getToken();
};
