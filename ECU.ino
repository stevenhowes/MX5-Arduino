#include "pins.h"
#include "data.h"
#include "schedule.h"
#include "tables.h"

void setup() {
  debug_setup();

  pinMode(pin_map, INPUT);

  pinMode(pin_tach, OUTPUT);
  pinMode(pin_coil1, OUTPUT);
  pinMode(pin_coil2, OUTPUT);
  pinMode(pin_coil3, OUTPUT);
  pinMode(pin_coil4, OUTPUT);

  digitalWrite(pin_tach, LOW);
  digitalWrite(pin_coil1, LOW);
  digitalWrite(pin_coil2, LOW);
  digitalWrite(pin_coil3, LOW);
  digitalWrite(pin_coil4, LOW);

  // Get an initial reading and output debug if it's not atmospheric
  map_init();
  battery_init();
}

void loop() {
  cas_process();
  schedule_process();
  
//  map_process();
//  cas_process();
//  tach_process();
//  ignition_process();
  

}

