#ifndef GroveTiltSwitch_H
#define GroveTiltSwitch_H

#include <Arduino.h>
#include "../Grove/Grove.h"

class GroveTiltSwitch {
	private:
		unsigned int _pin;
		boolean _state;
		void (*_callback)();
		
	public:
		GroveTiltSwitch(GrovePin pins);
		virtual ~GroveTiltSwitch() {};
		void initialize();
		boolean getState();
		void activateOnChange(void (*callback)());
		void deactivateOnChange();
};

#endif