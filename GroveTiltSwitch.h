#ifndef GroveTiltSwitch_H
#define GroveTiltSwitch_H

#include <Arduino.h>
#include <Grove.h>

class GroveTiltSwitch {
	private:
		unsigned int _pin;
		boolean _state;
		void (*_callback)();
		
	public:
		GroveTiltSwitch();
		virtual ~GroveTiltSwitch() {};
		void initialize(GrovePin pins);
		boolean getState();
		void activateOnChange(void (*callback)());
		void deactivateOnChange();
};

#endif