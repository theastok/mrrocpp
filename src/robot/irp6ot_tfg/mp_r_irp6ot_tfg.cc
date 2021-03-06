/*!
 * @file
 * @brief File contains mp robot class definition for IRp6 on track two finger gripper
 * @author twiniars <twiniars@ia.pw.edu.pl>, Warsaw University of Technology
 *
 * @ingroup irp6ot_tfg
 */

#include "robot/irp6ot_tfg/mp_r_irp6ot_tfg.h"
#include "robot/irp6ot_tfg/const_irp6ot_tfg.h"

namespace mrrocpp {
namespace mp {
namespace robot {

irp6ot_tfg::irp6ot_tfg(task::task &mp_object_l) :
	motor_driven(lib::irp6ot_tfg::ROBOT_IRP6OT_TFG, ECP_IRP6OT_TFG_SECTION, mp_object_l, IRP6OT_TFG_NUM_OF_SERVOS)
{
}

} // namespace robot
} // namespace mp
} // namespace mrrocpp
