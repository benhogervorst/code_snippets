/****************************************************************************\
    Author:  Ben Hogervorst
    Date:  02/04/2023
    Name:  Button Class
    Description:
        The purpose of this code is to create a simple interface class for 
        buttons on microcontroller (for this example code, an Arduino)

        The hardware aspects of the code is designed around a button which
        be wired across a digital pin and a GND.  When pressed, the digital pin
        is pulled to GND.

    Revisions:
        20230204:   Initial version of code, pulled from BatteryBank repository
\*****************************************************************************/

// REQUIRED LIBRARIES (for Arduino):
#include <Adafruit_GFX.h>

/*************************************************\
  Class: Button
  Data Members: Boolean state of button.
                Pin number of button.
  Methods:  Constructor
            init - initialize pin
            isReleased - get status of button
  Description: Keeps track of current status of
                button when pressed or released
\*************************************************/
class Button 
{
  private:
    bool _state;
    byte _pin;

  public:
    // constructor
    Button(byte pin) : _pin(pin) {}

    // begin watching button state
    void init() 
    {
      pinMode(_pin, INPUT_PULLUP);
      _state = !(digitalRead(_pin));
    }

    // get state of button when called
    bool isReleased() 
    {
      bool v = !(digitalRead(_pin));
      if (v != _state) 
      {
        _state = v;
        if (_state)
            return true;
      }
      return false;
    }
};
 
// EXAMPLE CODE (arduino):

// create a Button object called "button", parameter "4" is the digital pin
Button button(4);

void setup()
{
    // within setup, call the "init()" method of the button class
    button.init();
}

void loop()
{
    // call the "isReleased()" method, will return true if the button is pressed and released
    if(button.isReleased())
    {
        // do something
    }
}