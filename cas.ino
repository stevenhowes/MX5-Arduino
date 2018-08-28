void cas_process()
{
  // SGT is a pulse for TDC of *any* cylinder. By combining this with SGT it's possible to
  // identify which cylinder it is
  byte sgt = digitalRead(pin_cas_sgt);
  unsigned long timestamp = micros();

  // Find rising edge
  if(sgt == 1)
  {
    if(cas_sgt_lastvalue == 0)
    {
      // Handle tach
      task_tach_high = micros();

      cas_sgt_lastrise = timestamp;
    }
  }

  // Find falling edge
  if(sgt == 0)
  {
    if(cas_sgt_lastvalue == 1)
    {
      // Difference between last and current is 180 degrees
      usec_per_degree = (timestamp - cas_sgt_lastfall) / 180;

      cas_sgt_lastfall = timestamp;

      // If we have crank pulse present then cyl1 is TDC
      if(digitalRead(pin_cas_sgc) == HIGH)
      {
        cylinder_tdc = 1;
      }
      else
      {
        cylinder_tdc = cylinder_next[cylinder_tdc];
      }

      // Schedule next cylinder, this one is already past TDC
      cylinder_next_fire = cylinder_next[cylinder_tdc];
      if(cylinder_next_fire == 1)
      {
         task_coil1_fire = micros() + (usec_per_degree * 180);
         task_coil1_charge = task_coil1_fire - coil_dwell;
      }else if(cylinder_next_fire == 2)
      {
         task_coil2_fire = micros() + (usec_per_degree * 180);
         task_coil2_charge = task_coil2_fire - coil_dwell;
      }else if(cylinder_next_fire == 3)
      {
         task_coil3_fire = micros() + (usec_per_degree * 180);
         task_coil3_charge = task_coil3_fire - coil_dwell;
      }else if(cylinder_next_fire == 4)
      {
         task_coil4_fire = micros() + (usec_per_degree * 180);
         task_coil4_charge = task_coil4_fire - coil_dwell;
      }
    }
  }
  cas_sgt_lastvalue = sgt;


  // SGC is the once per revolution pulse. Used to identify when Cyl 1 is TDC (as opposed to 4)
  // and is also handy for determining RPM if you trigger on the leading edge
  byte sgc = digitalRead(pin_cas_sgc);
  timestamp = micros();

  // Find rising edge
  if(sgc == 1)
  {
    if(cas_sgc_lastvalue == 0)
    {
      // For rising edge (the consitent one) we need to update RPM
      rpm_current_value = 60000000 / (timestamp - cas_sgc_lastrise);

      cas_sgc_lastrise = timestamp;
    }
  }

  // Find falling edge
  if(sgc == 0)
  {
    if(cas_sgc_lastvalue == 1)
    {
      cas_sgc_lastfall= timestamp;
    }
  }
  cas_sgc_lastvalue = sgc;
}


