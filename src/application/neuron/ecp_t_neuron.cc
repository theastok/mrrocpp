/*
 * ecp_t_neuron.cc
 *
 *  Created on: May 13, 2010
 *      Author: tbem
 */

#include "robot/irp6ot_m/ecp_r_irp6ot_m.h"
#include "ecp_t_neuron.h"
#include "neuron_sensor.h"
#include "ecp_mp_t_neuron.h"
#include "ecp_mp_neuron_sensor.h"

namespace mrrocpp {
namespace ecp {
namespace irp6ot {
namespace task {

/*==============================Constructor==================================*/
//Constructors
Neuron::Neuron(lib::configurator &_config): task(_config){
	ecp_m_robot=new irp6ot_m::robot(*this);				//initialization of robot
	smoothGenerator=new common::generator::newsmooth(*this, lib::ECP_XYZ_ANGLE_AXIS, 6);
	sr_ecp_msg->message("ECP loaded Neuron");
};

/*============================Destructor=====================================*/
Neuron::~Neuron(){
	delete ecp_m_robot;
	delete neuronGenerator;
	delete smoothGenerator;
};

/*====================mp_2_ecp_next_state_string_handler=====================*/
void Neuron::mp_2_ecp_next_state_string_handler(void){
	if (mp_2_ecp_next_state_string == ecp_mp::task::ECP_T_NEURON) {
		neuronSensor = new ecp_mp::sensor::neuron_sensor(config);
		sensor_m[ecp_mp::sensor::ECP_MP_NEURON_SENSOR] = neuronSensor;
		neuronGenerator = new common::generator::neuron_generator(*this);
		neuronGenerator->sensor_m=sensor_m;

		int numberOfTrajectories=neuronSensor->getNumberOfTrajectories();
		printf("Number of trajecotries %d\n",numberOfTrajectories);

		std::vector<double> coordinates1(6);
		//smoothGenerator->set_debug(true);
		ecp_mp::sensor::Coordinates coordinates;
		for(int i=0;i<numberOfTrajectories;++i){
			printf("Loop number %d\n",i);
			coordinates=neuronSensor->getFirstCoordinates();
			printf("coordinates: %lf %lf %lf\n",coordinates.x,coordinates.y,coordinates.z);

			smoothGenerator->reset();
			smoothGenerator->set_absolute();

			coordinates1[0]=coordinates.x;
			coordinates1[1]=coordinates.y;
			coordinates1[2]=coordinates.z;
			coordinates1[3]=1.203;
			coordinates1[4]=-1.447;
			coordinates1[5]=-0.294;
			smoothGenerator->load_absolute_angle_axis_trajectory_pose(coordinates1);

			//smoothGenerator->set_debug(true);
			if(smoothGenerator->calculate_interpolate())
				smoothGenerator->Move();

			neuronGenerator->reset();
			neuronGenerator->Move();
		}

		neuronSensor->sendCommunicationFinished();
	}


}

/*====================mp_2_ecp_next_state_string_handler=====================*/
void Neuron::ecp_stop_accepted_handler(){
	sr_ecp_msg->message("mp_stop_pressed");
	delete sensor_m[ecp_mp::sensor::ECP_MP_NEURON_SENSOR];
}

}  //namespace task
} // namespace irp6ot

namespace common {
namespace task {

task* return_created_ecp_task(lib::configurator &_config){
	return new irp6ot::task::Neuron(_config);

}

} // namespace task
} // namespace common
} // namespace ecp
} // namespace mrrocpp

