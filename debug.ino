byte debug_live_index = 0;
byte debug_rpm = 0;

void debug_setup()
{
  Serial.begin(115200);

  // Flush
  Serial.println("");
  Serial.println("");

  // Now we have init we can do real loop
  task_debug = 1;
}

void task_debug_run()
{
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

  // If we're outputting live index - print it
  if(debug_live_index == 1)
  {
    Serial.print("IDX: ");
    Serial.println(rpm_current_index + (map_current_index << 4));
  }

  // If we're currently outputting RPM - print it
  if(debug_rpm == 1)
  {
    Serial.print("RPM: ");
    Serial.println(rpm_current_value);
  }
  
  // If we're being asked for something
  if (Serial.available() > 0)
  {
    // Kills ignition and injection until CAS re-sync (for safety in long I/O)
    task_debug_safekill();

    // Read the first char (the command)
    char readbyte = Serial.read();

    
    if(readbyte == 't') // Dump table
    {
      readbyte = Serial.read();

      // i for ignition and f for fel
      if(readbyte == 'f')
        task_debug_dumpfueltable();
      else if(readbyte == 'i')
        task_debug_dumpignitiontable();
    }
    else if(readbyte == 'T') // Ammend table
    {
      // Up to the first comma is the table (as on a read)
      String table = "";
      while(1)
      {
        readbyte = Serial.read();
        if(readbyte == ',')
          break;
        else
          table += readbyte;
      }

      // The next parameter is the index in the table (TODO: bounds check?)
      String index = "";
      while(1)
      {
        readbyte = Serial.read();
        if(readbyte == ',')
          break;
        else
          index += readbyte;
      }

      // The final section is the value in decimal (TODO: bounds check?)
      String value = "";
      while(1)
      {
        readbyte = Serial.read();
        if(readbyte == '\n')
          break;
        else
          value += readbyte;
      }

      // Update the value
      if(table == "i")
      {
        table_ignition[index.toInt()] = value.toInt();
      }else if(table == "f")
      {
        table_pulsewidth[index.toInt()] = value.toInt();
      }
    }else if(readbyte == 'i') // Disable index output
    {
      debug_live_index = 0;
    }else if(readbyte == 'I') // Enable index output
    {
      debug_live_index = 1;
    }else if(readbyte == 'r') // Disable RPM output
    {
      debug_rpm = 0;
    }else if(readbyte == 'R') // Enable RPM output
    {
      debug_rpm = 1;
    }
  }
}

// Outputs the fuel table as JSON
void task_debug_dumpfueltable()
{
  Serial.print("TBF: [");
  for(int i=0; i <= 255; i++)
  {
    Serial.print(table_pulsewidth[i]);
    if(i != 255)
    Serial.print(",");
  }
  Serial.print("]\n");
}

// Ignition table as json
void task_debug_dumpignitiontable()
{
  Serial.print("TBI: [");
  for(int i=0; i <= 255; i++)
  {
    Serial.print(table_ignition[i]);
    if(i != 255)
    Serial.print(",");
  }
  Serial.print("]\n");
}

// Stops charging all coils, closes all injectors
// Marks CAS as out of sync to prevent anything changing
void task_debug_safekill()
{
  // Stop charging coils
  task_coilx_fire_run(pin_coil1);
  task_coilx_fire_run(pin_coil2);

  // Close all injectors
  task_injectorx_close_run(pin_injector1);
  task_injectorx_close_run(pin_injector2);
  task_injectorx_close_run(pin_injector3);
  task_injectorx_close_run(pin_injector4);

  // Cancel all scheduled timing-sensitive events
  task_coil1_charge       =     0;
  task_coil1_fire         =     0;
  task_coil2_charge       =     0;
  task_coil2_fire         =     0;
  task_injector1_open       =     0;
  task_injector1_close      =     0;
  task_injector2_open       =     0;
  task_injector2_close      =     0;
  task_injector3_open       =     0;
  task_injector3_close      =     0;
  task_injector4_open       =     0;
  task_injector4_close      =     0;

  // And dont schedule any more until we're back in sync (two Cly1 TDC events matching predictions)
  cas_sync_fail=1;
  cas_sync_fail_log=0;
}

