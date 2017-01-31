# GroveTiltSwitch
Tilt Switch Library for Arduino + Grove shield

[Link to the tested grove module](http://wiki.seeed.cc/Grove-Tilt_Switch/)

##Example
```c++
#include <GroveTiltSwitch.h>

GroveTiltSwitch tiltSwitch;

void setup() {
  tiltSwitch.initialize(GROVE_D2);
  tiltSwitch.activateOnChange(stateChange);
  Serial.begin(9200);
}

void loop() {
  delay(500);
}

void stateChange() {
  Serial.println(tiltSwitch.getState() ? "HIGH" : "LOW");
}
```

##Documentation

###`void initialize(GrovePin pins)`
Initialize the sensor before using it.

Parameters:
- `pins`: Must be a digital socket (GROVE_D2 to GROVE_D8)

###`boolean getState()`
Return `true` is the switch is on.

###`void activateOnChange(void (*callback)())`
Parameters:
- `callback`: a function pointer that will be automatically executed when the switch's state change.
This works only if the sensor is pluged on GROVE_D2 or GROVE_D3 (to have access to the interruptions).

###`void deactivateOnChange()`
Stop auto executing the callback when the switch state change.