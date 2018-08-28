void debug_setup()
{
  Serial.begin(115200);
}

void task_debug_run()
{
  Serial.print("MAP = ");
  Serial.print(map_current_index);
  Serial.print(" (");
  Serial.print(map_current_value);
  Serial.print(")\t RPM = ");
  Serial.print(rpm_current_index);
  Serial.print(" (");
  Serial.print(rpm_current_value);
  Serial.println(")\t");
}

