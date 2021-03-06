// -------------------------------------------------------------------------
//                            sg_local.h
// Definicje struktur danych i metod dla procesu EDP on_track
//
// Ostatnia modyfikacja: 2006
// -------------------------------------------------------------------------


#ifndef __REGULATOR_SARKOFAG_H
#define __REGULATOR_SARKOFAG_H
#include "base/edp/edp_typedefs.h"
#include "base/edp/regulator.h"

namespace mrrocpp {
namespace edp {
namespace sarkofag {

#define SARKOFAG_SYNCHRO_STEP_COARSE -0.05
#define SARKOFAG_SYNCHRO_STEP_FINE   -0.02

#define SARKOFAG_INC_PER_REVOLUTION  4000.0  // Liczba impulsow enkodera na obrot walu - musi byc float
#define SARKOFAG_MAX_PWM_INCREMENT	1000
/*-----------------------------------------------------------------------*/
class NL_regulator_8_sarkofag: public common::NL_regulator {
	/* Klasa regulatorow konkretnych */
	// Obiekt z algorytmem regulacji

	long gripper_blocked_start_time;
	int sum_of_currents, current_index;

public:
	NL_regulator_8_sarkofag(uint8_t reg_no, uint8_t reg_par_no, double aa,
			double bb0, double bb1, double k_ff,
			common::motor_driven_effector &_master); // konstruktor

	virtual uint8_t compute_set_value(void);
	// obliczenie nastepnej wartosci zadanej dla napedu - metoda konkretna

}; // end: class NL_regulator_8
// ----------------------------------------------------------------------


} // namespace sarkofag
} // namespace edp
} // namespace mrrocpp


#endif
