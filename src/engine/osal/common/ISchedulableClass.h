/*
 * The <unnamed> factory builder project.
 *
 * \file TODO
 *
 * \brief An ISchedulableClass is a abstract class, which the resulting concrete object can be executed
 * 		by the in-game scheduler (e.g.: sprite update, game turns...)
 */

/*
 * CHANGELOG:
 * 14/04/2024: File creation (NG)
 */
#include <Types.h>

class ISchedulableClass
{
public:
	ISchedulableClass(s_Tick _period);

	virtual ~ISchedulableClass() = 0;

	virtual void tick() = 0;

	s_Tick getPeriod();

protected:
	s_Tick m_period;
};
