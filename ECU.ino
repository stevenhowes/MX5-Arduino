#include "pins.h"
#include "data.h"
#include "schedule.h"
#include "tables.h"

void setup() {
  // Sensors
  pinMode(pin_map, INPUT);
  pinMode(pin_batt, INPUT);

  // Dash / debug outputs
  pinMode(pin_tach, OUTPUT);
  digitalWrite(pin_tach, LOW);

  // Ignition outputs
  pinMode(pin_coil1, OUTPUT);
  pinMode(pin_coil2, OUTPUT);
  digitalWrite(pin_coil1, LOW);
  digitalWrite(pin_coil2, LOW);

  // Set up serial speed etc and do intro output
  debug_setup();
  
  // Get an initial reading and output debug if it's not atmospheric
  map_init();
  battery_init();
}

void loop() {
   // Always process the CAS
  cas_process();

  // Run scheduler
  schedule_process();
}

