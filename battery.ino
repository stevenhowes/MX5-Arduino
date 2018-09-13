void battery_init()
{
  task_battery_run();

  if(battery_voltage_value < 12)
  {
    Serial.println("ERR: Battery low");
  }
  else if(battery_voltage_value > 14)
  {
    Serial.println("ERR: Battery high");
  }
  else
    Serial.println("INF: Battery ok");
}

void task_battery_run()
{
  battery_voltage_value = map(analogRead(pin_batt), battery_cal_7v, battery_cal_16v, 7, 16);
  battery_voltage_index = constrain(battery_voltage_value,7,16) - 7;
}


