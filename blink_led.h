class blink_led
{
  public:
    blink_led(byte _pin)
    {
      pin = _pin;
      pinMode(pin, OUTPUT);
    }
    void on()
    {
      i = 0;
      status = 1;
    }

    void on(uint16_t _mode)
    {
      setMode(_mode);
      i = 0;
      status = 1;
    }
    void off()
    {
      status = 0;
      digitalWrite(pin, LOW);
    }

    void setInterval(unsigned int _interval)
    {
      interval = _interval;
    }

    void setMode(uint16_t _mode)
    {
      mode = _mode;
    }

    void update()
    {
      if (status)
      {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) 
        {
          previousMillis = currentMillis;
          digitalWrite(pin, (mode >> i) % 2);
          if (++i == 16) i = 0;
        }
      }
    }

  private:
    byte pin;
    byte status = 0;
    unsigned long previousMillis;
    long interval = 125;
    uint16_t mode;
    byte i;
};
