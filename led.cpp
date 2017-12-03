/*
 * led.cpp
 *
 * Created:1 0/20/2017
 *  Author: Troy Condit
 */ 

 #include "led.h"


Led::Led(Gpio port, enum drive d )
	:gpio_(port)
	,drive_(d)
{}
//
//
//
void Led::on( )
{ 
	if(drive_ == HIGH )
		gpio_.set();	
	else 
		gpio_.clear();
}
//
//
//
void Led::off()
{ 
	if(drive_ == HIGH )
		gpio_.clear();
	else
		gpio_.set();
}
//
//
//
void Led::set( bool on )
{
	if(on)
		this->on();
	 else
		this->off();
}
//
//
//
void Led::toggle()
{
	gpio_.toggle();
}
//
//
//
bool Led::isOn()
{
	return gpio_.value() == drive_; 
}