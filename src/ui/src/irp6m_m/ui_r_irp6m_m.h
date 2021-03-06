// -------------------------------------------------------------------------
//                            ui_class.h
// Definicje klasy Ui
//
// Ostatnia modyfikacja: 2010
// -------------------------------------------------------------------------

#ifndef __UI_R_IRP6M_M_H
#define __UI_R_IRP6M_M_H

#include "ui/src/ui.h"
#include "ui/src/ui_robot.h"
#include "robot/irp6_mechatronika/const_irp6m.h"

//
//
// KLASA UiRobotIrp6m_m
//
//


// super klasa agregujaca porozrzucane struktury

class Ui;
class ui_irp6_common_robot;

class UiRobotIrp6m_m : public UiRobot
{
private:

public:

	double irp6m_current_pos[lib::irp6m::NUM_OF_SERVOS]; // pozycja biezaca
	double irp6m_desired_pos[lib::irp6m::NUM_OF_SERVOS]; // pozycja zadana

	bool is_wind_irp6m_int_open; // informacja czy okno ruchow w radianach stawow jest otwarte
	bool is_wind_irp6m_inc_open; // informacja czy okno ruchow w radianach na wale silnika jest otwarte
	bool is_wind_irp6m_xyz_euler_zyz_open; // informacja czy okno ruchow we wspolrzednych zewnetrznych jest otwarte
	bool is_wind_irp6m_xyz_angle_axis_open; // informacja czy okno ruchow we wspolrzednych zewnetrznych jest otwarte
	bool is_wind_irp6m_xyz_angle_axis_ts_open; // informacja czy okno definicji narzedzia we wspolrzednych zewnetrznych jest otwarte
	bool is_wind_irp6m_xyz_euler_zyz_ts_open; // informacja czy okno definicji narzedzia we wspolrzednych zewnetrznych jest otwarte
	bool is_wind_irp6m_kinematic_open; // informacja czy okno definicji kinematyki jest otwarte
	bool is_wind_irp6m_servo_algorithm_open; // informacja czy okno definicji kinematyki jest otwarte

	ui_irp6_common_robot *ui_ecp_robot;

	UiRobotIrp6m_m(Ui& _ui);
	int reload_configuration();
	int manage_interface();
	int
			process_control_window_irp6m_section_init(bool &wlacz_PtButton_wnd_processes_control_all_reader_start, bool &wlacz_PtButton_wnd_processes_control_all_reader_stop, bool &wlacz_PtButton_wnd_processes_control_all_reader_trigger);
	int close_all_windows();
	int delete_ui_ecp_robot();

};

#endif

