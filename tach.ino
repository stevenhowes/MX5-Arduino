void task_tach_low_run()
{
    digitalWrite(pin_tach, LOW);
}

void task_tach_high_run()
{
  digitalWrite(pin_tach, HIGH);

  // Auto-schedule the end
  task_tach_low = micros() + tach_pulse_length;
}

