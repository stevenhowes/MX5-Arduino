

void schedule_process()
{
  byte tasks = 0;
  
  // Coil 1
  if((task_coil1_fire > 0) && (micros() > task_coil1_fire))
  {
      task_coilx_fire_run(pin_coil1);
      task_coil1_fire = 0;
      tasks++;
  }else if((task_coil1_charge > 0) && (micros() > task_coil1_charge))
  {
      task_coilx_charge_run(pin_coil1);
      task_coil1_charge = 0;
      tasks++;
  }

  // Coil 2
  if((task_coil2_fire > 0) && (micros() > task_coil2_fire))
  {
      task_coilx_fire_run(pin_coil2);
      task_coil2_fire = 0;
      tasks++;
  }else if((task_coil2_charge > 0) && (micros() > task_coil2_charge))
  {
      task_coilx_charge_run(pin_coil2);
      task_coil2_charge = 0;
      tasks++;
  }

  // Only carry on to the lower priority stuff if we did nothing else
  if(tasks > 0)
    return;

  // These should never clash, but if they do then only do MAP, RPM can't have shifted much
  if(micros() > task_map)
  {
    task_map = micros() + task_map_interval;
    task_map_run();
    tasks++;
  }else if(micros() > task_rpm)
  {
    task_rpm = micros() + task_rpm_interval;
    task_rpm_run();
    tasks++;
  }else if(micros() > task_battery)
  {
    task_battery = micros() + task_battery_interval;
    task_battery_run();
    tasks++;
  }

  // We never high and low at the same time
  if((task_tach_high > 0) && (micros() > task_tach_high))
  {
      task_tach_high_run();
      task_tach_high = 0;
      tasks++;
  }else if((task_tach_low > 0) && (micros() > task_tach_low))
  {
      task_tach_low_run();
      task_tach_low = 0;
      tasks++;
  }

  // Dont do debug output unless we have nothing better to do
  if(tasks > 0)
    return;

  if((task_debug > 0) && (micros() > task_debug))
  {
      task_debug_run();
      task_debug = micros() + task_debug_interval;
  }
}


