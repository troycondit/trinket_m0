/*
 * gpio.cpp
 *
 * Created: 10/20/2017
 *  Author: Troy Condit
 */ 
 #include "gpio.h"

Gpio::Gpio( int pin, int port, enum direction  d )
	:pin_(pin)
	,port_(port)
	,direction_(d)
{
	if( pin_ == PIN_NULL )
		return;

	if(direction_ == IN )
	{
		PORT->Group[port_].DIRCLR.bit.DIRCLR = d << pin_;
		PORT->Group[port_].PINCFG[pin_].bit.INEN = 1;
	}	
	else
	{
		PORT->Group[port_].DIRSET.bit.DIRSET = d << pin_;
	}
};
//
//
//
void Gpio::set(bool value )
{ 
	if( pin_ == PIN_NULL )
		return;
	if( value )
		PORT->Group[port_].OUTSET.bit.OUTSET = value << pin_;
	else
		this->clear();
}
//
//
//
void Gpio::clear()	
{ 
	if( pin_ == PIN_NULL )
		return;
	PORT->Group[port_].OUTCLR.bit.OUTCLR =  1 << pin_;
}
//
//
//
void Gpio::toggle()	
{ 
	if( pin_ == PIN_NULL )
		return;
	PORT->Group[port_].OUTTGL.bit.OUTTGL =  1 << pin_;
}
//
//
//
bool Gpio::value()	
{ 
	if( pin_ == PIN_NULL )
		return 0;
	if(direction_ == IN )
		return  PORT->Group[port_].IN.reg & (1 << pin_);
	//else
	return  PORT->Group[port_].OUT.reg & (1 << pin_);
}
