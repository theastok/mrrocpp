// -------------------------------------------------------------------------
//                            ecp_g_legobrick.h dla QNX6
// Generator dla zadania legobrick
// 
// -------------------------------------------------------------------------

#if !defined(_ECP_GEN_LEGOBRICK_CONV_H)
#define _ECP_GEN_LEGOBRICK_CONV_H

#include "common/com_buf.h"		// trajectory_description

#include "ecp/common/ecp_generator.h"

// --------------------------------------------------------------------------
// Generator trajektorii prostoliniowej dla zadan yoyka z wodzeniem za nos
class conveyor_incremental_move: public ecp_generator {
	double move_length;
	double current_pose;
	double next_pose;
	double begin_pose;
	int first;
	int step;
public:	
	trajectory_description td;
	
	// konstruktor
	conveyor_incremental_move(ecp_task& _ecp_task, double inc_move);  
	
	virtual bool first_step ();

	virtual bool next_step ();

}; // end:
// --------------------------------------------------------------------------

#endif
