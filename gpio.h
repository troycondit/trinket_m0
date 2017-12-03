/*
 * gpio.h
 *
 * Created: 10/20/2017
 *  Author: Troy Condit
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "samd21e18a.h"
#include "sam.h"
//#include "port.h"

class Gpio
{
	enum direction {IN,OUT};
	#define PIN_NULL 0xFFFF
	public:
		Gpio( int pin, int port = 0, enum direction  d = OUT );
		void set(bool value = true);
		void clear();	
		void toggle();	
		bool value();	

	private:
		int pin_;
		int port_;
		enum direction direction_;
};


#endif /* GPIO_H_ */