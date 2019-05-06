void battery_init()
{
  // Run once to get start info
  task_battery_run();

  // Log if battery is exceptional in any way
  if(battery_voltage_value < 12)
  {
    Serial.println("ERR: Battery low");
  }
  else if(battery_voltage_value > 15)
  {
    Serial.println("ERR: Battery high");
  }
}

void task_battery_run()
{
  // Min/Max we care about are 7 and 16. Anything that low or high is bad so outside of that
  // doesn't need any special consideration
  battery_voltage_value = map(analogRead(pin_batt), battery_cal_7v, battery_cal_16v, 7, 16);

  // Nudge it along so we have an index starting at 0 for tables etc
  battery_voltage_index = constrain(battery_voltage_value,7,16) - 7;
}
