void map_init()
{
  task_map_run();

  if(map_current_value < 87)
    Serial.println("ERR: MAP low");
  else if(map_current_value > 108)
    Serial.println("ERR: MAP high ");
  else
    Serial.println("INF: MAP ok");
}

void task_map_run()
{
  map_current_value = map(analogRead(pin_map), 0, 1023, map_sensor_min_kpa, map_sensor_max_kpa);
  map_current_index = map(map_current_value, map_range_min, map_range_max, 0, 15);
  map_current_index = constrain(map_current_index,0,15);
}


