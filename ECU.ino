#include "pins.h"
#include "data.h"
#include "schedule.h"
#include "tables.h"
void(* resetFunc) (void) = 0; //declare reset function @ address 0

void setup() {
  // Sensors
  pinMode(pin_map, INPUT);
  pinMode(pin_batt, INPUT);
  pinMode(pin_throttle, INPUT);
  
  // Dash / debug outputs
  pinMode(pin_tach, OUTPUT);
  digitalWrite(pin_tach, LOW);

  // Ignition outputs
  pinMode(pin_coil1, OUTPUT);
  pinMode(pin_coil2, OUTPUT);
  digitalWrite(pin_coil1, LOW);
  digitalWrite(pin_coil2, LOW);

  // Injector Outputs
  pinMode(pin_injector1, OUTPUT);
  pinMode(pin_injector2, OUTPUT);
  pinMode(pin_injector3, OUTPUT);
  pinMode(pin_injector4, OUTPUT);
  digitalWrite(pin_injector1, LOW);
  digitalWrite(pin_injector2, LOW);
  digitalWrite(pin_injector3, LOW);
  digitalWrite(pin_injector4, LOW);

  // Set up serial speed etc and do intro output
  debug_setup();
  
  // Get initial values and check they are sane
  map_init();
  battery_init();
  throttle_init();
}

void loop() {
   // Always process the CAS
  cas_process();

  // Run scheduler
  schedule_process();
}
