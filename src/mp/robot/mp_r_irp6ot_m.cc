#include "mp/robot/mp_r_irp6ot_m.h"

namespace mrrocpp {
namespace mp {
namespace robot {

irp6ot_m::irp6ot_m(task::task &mp_object_l) :
	manip_and_conv(lib::ROBOT_IRP6OT_M, ECP_IRP6OT_M_SECTION, mp_object_l, IRP6OT_M_NUM_OF_SERVOS),
	ft_data_buffer(mp_object, lib::ROBOT_IRP6OT_M + ":ForceTorque")
{
}

} // namespace robot
} // namespace mp
} // namespace mrrocpp

