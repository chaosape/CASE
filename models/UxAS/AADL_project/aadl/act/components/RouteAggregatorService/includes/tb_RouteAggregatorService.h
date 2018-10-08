#ifndef __tb_AADL_RouteAggregatorService_types__H
#define __tb_AADL_RouteAggregatorService_types__H

#include <tb_uxas_processor_types.h>

bool tb_GroundVehicleConfiguration_in_dequeue(IMPACT__GroundVehicleConfiguration_i * tb_GroundVehicleConfiguration_in);
bool tb_SurfaceVehicleConfiguration_in_dequeue(IMPACT__SurfaceVehicleConfiguration_i * tb_SurfaceVehicleConfiguration_in);
bool tb_AirVehicleConfiguration_in_dequeue(CMASI__AirVehicleConfiguration_i * tb_AirVehicleConfiguration_in);
bool tb_RouteRequest_in_dequeue(ROUTE__RouteRequest_i * tb_RouteRequest_in);
bool tb_GroundVehicleState_in_dequeue(IMPACT__GroundVehicleState_i * tb_GroundVehicleState_in);
bool tb_UniqueAutomationRequest_in_dequeue(UXTASK__UniqueAutomationRequest_i * tb_UniqueAutomationRequest_in);
bool tb_RoutePlanResponse_in_dequeue(ROUTE__RoutePlanResponse_i * tb_RoutePlanResponse_in);
bool tb_SurfaceVehicleState_in_dequeue(IMPACT__SurfaceVehicleState_i * tb_SurfaceVehicleState_in);
bool tb_TaskPlanOptions_in_dequeue(UXTASK__TaskPlanOptions_i * tb_TaskPlanOptions_in);
bool tb_AirVehicleState_in_dequeue(CMASI__AirVehicleState_i * tb_AirVehicleState_in);
bool tb_ServiceStatus_out_enqueue(const CMASI__ServiceStatus_i * tb_ServiceStatus_out);
bool tb_RoutePlanRequest_out_enqueue(const ROUTE__RoutePlanRequest_i * tb_RoutePlanRequest_out);
bool tb_AssignmentCostMatrix_out_enqueue(const UXTASK__AssignmentCostMatrix_i * tb_AssignmentCostMatrix_out);
bool tb_RouteResponse_out_enqueue(const ROUTE__RouteResponse_i * tb_RouteResponse_out);

#endif // __tb_AADL_RouteAggregatorService_types__H
