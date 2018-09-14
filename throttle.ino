void throttle_init()
{
  task_throttle_run();
}

void task_throttle_run()
{
  throttle_previous_2_value = throttle_previous_1_value;
  throttle_previous_1_value = throttle_current_value;
  throttle_current_value = map(analogRead(pin_throttle), 0, 1023, 0, 100);
}


