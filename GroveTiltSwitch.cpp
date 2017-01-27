#include "GroveTiltSwitch.h"

GroveTiltSwitch::GroveTiltSwitch(GrovePin pins) {
	this->_pin = pins.pin1;
	this->_state = false;
}

void GroveTiltSwitch::initialize() {	
	pinMode(this->_pin, INPUT_PULLUP);
}

boolean GroveTiltSwitch::getState() {
	this->_state = digitalRead(this->_pin);
	return this->_state;
}

void GroveTiltSwitch::activateOnChange(void(*callback)()) {
	this->_callback = callback;
	attachInterrupt(digitalPinToInterrupt(this->_pin), this->_callback, CHANGE);
}

void GroveTiltSwitch::deactivateOnChange() {
	detachInterrupt(digitalPinToInterrupt(this->_pin));
}