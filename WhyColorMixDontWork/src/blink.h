void blink(int pin, int x)
{
    digitalWrite(pin, 1);
    delay(x);
    digitalWrite(pin, 0);
    delay(x);
}