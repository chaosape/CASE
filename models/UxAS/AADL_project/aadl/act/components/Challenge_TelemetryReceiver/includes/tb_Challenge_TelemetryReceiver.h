#ifndef __tb_AADL_Challenge_TelemetryReceiver_types__H
#define __tb_AADL_Challenge_TelemetryReceiver_types__H

#include <tb_uxas_processor_types.h>

bool tb_VideoRecord_in_dequeue(UXNATIVE__VideoRecord_i * tb_VideoRecord_in);
bool tb_AirVehicleState_in_dequeue(CMASI__AirVehicleState_i * tb_AirVehicleState_in);

#endif // __tb_AADL_Challenge_TelemetryReceiver_types__H