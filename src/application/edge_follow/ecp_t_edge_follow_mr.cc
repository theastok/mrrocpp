/*!
 * @file
 * @brief File contains edge_follow_mr ecp_task class definition of unknown contour following application.
 * @author twiniars <twiniars@ia.pw.edu.pl>, Warsaw University of Technology
 *
 * @ingroup edge_follow
 */

#include <cstdio>

#include "robot/irp6ot_m/ecp_r_irp6ot_m.h"
#include "robot/irp6p_m/ecp_r_irp6p_m.h"

#include "ecp_t_edge_follow_mr.h"

#include "ecp_st_edge_follow.h"
#include "subtask/ecp_st_bias_edp_force.h"
#include "subtask/ecp_st_tff_nose_run.h"
#include "generator/ecp/ecp_g_force.h"

namespace mrrocpp {
namespace ecp {
namespace common {
namespace task {

// KONSTRUKTORY
edge_follow_mr::edge_follow_mr(lib::configurator &_config) :
	task(_config)
{
	// the robot is choose dependendat on the section of configuration file sent as argv[4]
	if (config.section_name == lib::irp6ot_m::ECP_SECTION) {
		ecp_m_robot = new irp6ot_m::robot(*this);
	} else if (config.section_name == ECP_IRP6P_M_SECTION) {
		ecp_m_robot = new irp6p_m::robot(*this);
	} else {
		// TODO: throw
	}

	// utworzenie podzadan
	{
		ecp_sub_task* ecpst;
		ecpst = new ecp_sub_task_edge_follow(*this);
		subtask_m[ecp_mp::task::ECP_ST_EDGE_FOLLOW] = ecpst;

		ecpst = new ecp_sub_task_bias_edp_force(*this);
		subtask_m[ecp_mp::task::ECP_ST_BIAS_EDP_FORCE] = ecpst;
	}

	{
		ecp_sub_task_tff_nose_run* ecpst;
		ecpst = new ecp_sub_task_tff_nose_run(*this);
		subtask_m[ecp_mp::task::ECP_ST_TFF_NOSE_RUN] = ecpst;
		ecpst->nrg->configure_pulse_check(true);
	}

	sr_ecp_msg->message("ecp edge_follow_MR loaded");
}

task* return_created_ecp_task(lib::configurator &_config)
{
	return new common::task::edge_follow_mr(_config);
}

}
} // namespace common
} // namespace ecp
} // namespace mrrocpp
