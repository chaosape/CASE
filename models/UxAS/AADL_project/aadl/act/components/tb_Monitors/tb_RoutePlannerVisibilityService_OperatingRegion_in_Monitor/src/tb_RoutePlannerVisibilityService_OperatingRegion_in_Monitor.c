#include "../../../../include/tb_RoutePlannerVisibilityService_OperatingRegion_in_Monitor.h"
#include "../include/tb_uxas_processor_types.h"

int mon_get_sender_id(void);
int monsig_emit(void);

CMASI__OperatingRegion_i contents[1];
static uint32_t front = 0;
static uint32_t length = 0;

static bool is_full(void) {
  return length == 1;
}

static bool is_empty(void) {
  return length == 0;
}

bool mon_dequeue(CMASI__OperatingRegion_i * m) {
  if (mon_get_sender_id() != TB_MONITOR_READ_ACCESS) {
    return false;
  } else if (is_empty()) {
    return false;
  } else {
    *m = contents[front];
    front = (front + 1) % 1;
    length--;
    return true;
  }
}

bool mon_enqueue(const CMASI__OperatingRegion_i * m) {
  if (mon_get_sender_id() != TB_MONITOR_WRITE_ACCESS) {
    return false;
  } else if (is_full()) {
    return false;
  } else {
    contents[(front + length) % 1] = *m;
    length++;
    monsig_emit();
    return true;
  }
}