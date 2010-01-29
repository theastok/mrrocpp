// -------------------------------------------------------------------------
//                            task/mp_t_ball.h
//
// MP task for two robot ball device
// Ostatnia modyfikacja: 2007
// -------------------------------------------------------------------------

#if !defined(__MP_T_HAPTIC_H)
#define __MP_T_HAPTIC_H

#include "mp/mp.h"


namespace mrrocpp {
namespace mp {
namespace task {

/** @defgroup ball Haptic coupling
 *  @ingroup application
 *  A two robot application of IRp6 manipulator's in ball coupling
 *  @{
 */

class ball : public task
{
protected:

	void configure_edp_force_sensor(bool configure_track, bool configure_postument);

public:

	ball(lib::configurator &_config);

	// methods for mp template
	void main_task_algorithm(void);

};

/** @} */ // end of edge_following

} // namespace task
} // namespace mp
} // namespace mrrocpp

#endif