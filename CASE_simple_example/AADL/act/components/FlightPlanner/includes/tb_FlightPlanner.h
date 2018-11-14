#ifndef __tb_AADL_FlightPlanner_types__H
#define __tb_AADL_FlightPlanner_types__H

#include "../../../includes/tb_PROC_HW_types.h"

bool tb_flight_plan_write(const SW__Mission_Impl * tb_flight_plan);

bool tb_recv_map_dequeue(SW__Command_Impl * tb_recv_map);

bool tb_position_status_dequeue(SW__Coordinate_Impl * tb_position_status);

#endif // __tb_AADL_FlightPlanner_types__H
