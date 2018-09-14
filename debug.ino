void debug_setup()
{
  Serial.begin(115200);

  Serial.println("");
  Serial.println("");

  Serial.print("DAT: ");
  Serial.print("map_current_index");
  Serial.print(",");
  Serial.print("rpm_current_index");
  Serial.print(",");
  Serial.print("battery_voltage_index");
  Serial.print(",");
  Serial.print("map_current_value");
  Serial.print(",");
  Serial.print("rpm_current_value");
  Serial.print(",");
  Serial.print("battery_voltage_value");
  Serial.print(",");
  Serial.print("throttle_current_value");
  Serial.println("");

  // Now we have init we can do real loop
  task_debug = 1;
}

void task_debug_run()
{
  Serial.print("DAT: ");
  Serial.print(map_current_index);
  Serial.print(",");
  Serial.print(rpm_current_index);
  Serial.print(",");
  Serial.print(battery_voltage_index);
  Serial.print(",");
  Serial.print(map_current_value);
  Serial.print(",");
  Serial.print(rpm_current_value);
  Serial.print(",");
  Serial.print(battery_voltage_value);
  Serial.print(",");
  Serial.print(throttle_current_value);
  Serial.println("");

  // Log if we're out of sync timing-wise
  if(cas_sync_fail_log > 0)
  {
    Serial.println("ERR: CAS sync fail");
    cas_sync_fail_log = 0;
  }

  // Log if we've gone over RPM
  if(rpm_limited_log > 0)
  {
    Serial.println("ERR: RPM limit");
    rpm_limited_log = 0;
  } 
}


