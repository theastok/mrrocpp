/**
 * @file generator/ecp_g_cvfradia.cc
 * @brief Generator responsible for communication with cvFraDIA (testing purposes).
 * - class definition
 * @author tkornuta
 * @date 17.03.2008
 *
 * $URL$
 * $LastChangedRevision$
 * $LastChangedDate$
 * $LastChangedBy$
 */

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <unistd.h>

#include "lib/typedefs.h"
#include "lib/impconst.h"
#include "lib/com_buf.h"

#include "lib/srlib.h"
#include "ecp/common/generator/ecp_g_cvfradia.h"

namespace mrrocpp {
namespace ecp {
namespace common {
namespace generator {

/*!
 * First step method.. .
 */
bool cvfradia::first_step()
{
	// Set robot parameters.
/*	the_robot->ecp_command.instruction.instruction_type = lib::GET;
	the_robot->ecp_command.instruction.get_type = ARM_DEFINITION;
	the_robot->ecp_command.instruction.get_arm_type = lib::FRAME;
	the_robot->ecp_command.instruction.interpolation_type
			= EXTERNAL_INTERPOLATION_WITH_FORCE;*/

	if (the_robot) the_robot->communicate_with_edp=false;

	return true;
}

/*!
 * Next step method.
 */
bool cvfradia::next_step()
{
	// Wait for 0.2s.
	usleep(200000);
	// Check trigger.
/*	if (check_and_null_trigger())
	{
		return false;
	}*/
	return true;
}

} // namespace generator
} // namespace common
} // namespace ecp
} // namespace mrrocpp

