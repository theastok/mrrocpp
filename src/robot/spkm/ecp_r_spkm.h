#if !defined(_ECP_R_SPKM_H)
#define _ECP_R_SPKM_H

/*!
 * @file
 * @brief File contains ecp robot class declaration for SwarmItFix Parallel Kinematic Machine
 * @author twiniars <twiniars@ia.pw.edu.pl>, Warsaw University of Technology
 *
 * @ingroup spkm
 */

#include "base/ecp/ecp_robot.h"
#include "robot/spkm/const_spkm.h"
#include "base/kinematics/kinematics_manager.h"
#include "robot/spkm/kinematic_model_spkm.h"

namespace mrrocpp {
namespace ecp {
namespace spkm {

// ---------------------------------------------------------------
class robot : public common::robot::ecp_robot, public kinematics::common::kinematics_manager
{
	// Klasa dla robota irp6_postument (sztywnego)
protected:
	//bufory wejsciowe z generatora
	lib::single_thread_port <lib::epos::epos_cubic_command> epos_cubic_command_data_port;
	lib::epos::epos_cubic_command epos_cubic_command_structure;

	lib::single_thread_port <lib::epos::epos_trapezoidal_command> epos_trapezoidal_command_data_port;
	lib::epos::epos_trapezoidal_command epos_trapezoidal_command_structure;

	lib::single_thread_port <lib::epos::epos_operational_command> epos_operational_command_data_port;
	lib::epos::epos_operational_command epos_operational_command_structure;

	lib::single_thread_port <bool> epos_brake_command_data_port;
	bool epos_brake_command_structure;

	/*
	 lib::single_thread_port <lib::epos_gen_parameters> epos_gen_parameters_data_port;
	 lib::epos_gen_parameters epos_gen_parameters_structure;
	 */
	// bufor wyjsciowe do generatora
	lib::single_thread_request_port <lib::epos::epos_reply> epos_reply_data_request_port;
	lib::epos::epos_reply epos_reply_structure;

	// bufory do edp
	lib::spkm::cbuffer ecp_edp_cbuffer;
	lib::spkm::rbuffer edp_ecp_rbuffer;

	void create_kinematic_models_for_given_robot(void);

public:
	robot(lib::configurator &_config, lib::sr_ecp &_sr_ecp);
	robot(common::task::task& _ecp_object);

	void create_command();
	void get_reply();

}; // end: class ecp_irp6_mechatronika_robot
// ---------------------------------------------------------------

} // namespace spkm
} // namespace ecp
} // namespace mrrocpp

#endif
