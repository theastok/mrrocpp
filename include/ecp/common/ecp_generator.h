#if !defined(_ECP_GENERATOR_H)
#define _ECP_GENERATOR_H

#include <map>

#include "ecp/common/ecp_task.h"
#include "ecp/common/ecp_robot.h"
#include "ecp_mp/ecp_mp_generator.h"

class ecp_generator : public ecp_mp_generator {

  protected:
	bool is_robot_active;
	ecp_task& ecp_t;
    	
 public:
 
	ecp_robot* the_robot;

	ecp_generator(ecp_task& _ecp_task, bool _is_robot_active);
		
	virtual ~ecp_generator();
  
	bool is_EDP_error (ecp_robot& the_robot) const;

	class ECP_error {  // Klasa obslugi bledow generatora
	public:
       uint64_t error_class;
       uint64_t error_no;
       edp_error error;

       ECP_error ( uint64_t err_cl, uint64_t err_no, uint64_t err0 = 0, uint64_t err1 = 0);
   }; // end: class ECP_error

}; // end: class ecp_generator

#endif /* _ECP_GENERATOR_H */
