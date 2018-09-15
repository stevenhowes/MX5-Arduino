void task_injectorx_close_run(int pin)
{
    digitalWrite(pin, LOW);
}

void task_injectorx_open_run(int pin)
{
    digitalWrite(pin, HIGH);
}

