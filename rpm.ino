void task_rpm_run()
{
  // Calculate our 4-bit table index
  rpm_current_index = map(rpm_current_value, rpm_range_min, rpm_range_max, 0, 15);

  // Dont exceed table
  rpm_current_index = constrain(rpm_current_index,0,15);
}
