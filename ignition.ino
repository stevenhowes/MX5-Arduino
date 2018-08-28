void task_coilx_fire_run(int pin)
{
    digitalWrite(pin, LOW);
}

void task_coilx_charge_run(int pin)
{
    digitalWrite(pin, HIGH);
}
