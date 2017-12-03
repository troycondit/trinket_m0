/*
 * Led.h
 *
 * Created: 10/20/2017
 *  Author: Troy
 */ 


#ifndef LED_H_
#define LED_H_

#include "gpio.h"

class Led 
{
	enum drive{LOW,HIGH};// which GPIO state will light the LED?   
	public:
		Led( Gpio port, enum drive d = HIGH );
		void on();
		void off();
		void set(bool on = true);
		void toggle();
		bool isOn();

	private:
		Gpio gpio_;
		enum drive drive_;
};




#endif /* LED_H_ */