void task_tach_low_run()
{
    digitalWrite(pin_tach, LOW);
}

void task_tach_high_run()
{
  digitalWrite(pin_tach, HIGH);

  // Schedule the end
  task_tach_low = micros() + tach_pulse_length;
}


