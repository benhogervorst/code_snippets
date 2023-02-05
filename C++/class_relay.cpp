/****************************************************************************\
    Author:  Ben Hogervorst
    Date:  02/04/2023
    Name:  Relay Class
    Description:
        The purpose of this code is to create a simple interface class for 
        using relays with a microcontroller (for this example code, an Arduino)

        The hardware aspects of the code is designed around a relay that is
        closed with a logic-level high signal

    Revisions:
        20230204:   Initial version of code, pulled from BatteryBank repository
\*****************************************************************************/

// REQUIRED LIBRARIES (for Arduino):
#include <Adafruit_GFX.h>

/*************************************************\
  Class: Relay
  Data Members: Boolean state of relay.
                Pin number of relay.
  Methods:  Constructor
            init - initialize pin
            getState - get state data member
            open - open the relay
            close - close the relay
            toggle - toggle current relay status
  Description: Keeps track of current status of
                relay and controls it
\*************************************************/
class Relay 
{
  private:
    bool _state;
    byte _pin;

  public:
    // constructor
    Relay(byte pin) : _pin(pin) {}

    // initialize relay
    void init() 
    {
      pinMode(_pin, INPUT_PULLUP);
      pinMode(_pin, OUTPUT);  
      digitalWrite(_pin, HIGH);
      _state = false;
    }

    // get relay state
    bool getState() { return _state; }

    // open relay
    void open()
    {
      digitalWrite(_pin, LOW);
      _state = true;
    }

    // close relay
    void close()
    {
      digitalWrite(_pin, HIGH);
      _state = false;
    }

    // toggle relay state
    bool toggle()
    {
      if (_state)
        close();
      else
        open();
      return _state;
    }
};

// EXAMPLE CODE (for Arduino)

// create a Relay object called "relay", parameter "2" is the digital pin
Relay relay(2);

void setup()
{
    // within setup, call the "init()" method of the button class
    relay.init();
}

void loop()
{
    // call various methods built into the Relay class
    relay.open();
    relay.close();
    relay.toggle();
    bool state = relay.getState();
}