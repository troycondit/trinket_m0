/*
 * ADA102_RGB.h
 *
 * Created: 10/20/2017
 *  Author: Troy Condit
 *
 *  Bit bang driver for a single ADA102 RGB LED
 *  RAII  LED is turned off during instantiation.
 *
  */ 


#ifndef ADA102_RGB_H_
#define ADA102_RGB_H_
#include "spi_bb.h"


class ADA102_RGB
{
public:
	ADA102_RGB(Spi_bb spi_port );
	void rgbb(char red, char green, char blue, char brightness );
	void rgb(uint32_t color);
	void brightness(char val); //brightness in the range of 0 31
	void red(char val); //Red level in the range of 0 255
	void green(char val); //Green level in the range of 0 255
	void blue(char val); //Green level in the range of 0 255
private:
	
	void spi_send_color(void);
	//void spi_tx(char data);
	Spi_bb spi_port_;
	char red_;
	char green_;
	char blue_;
	char brightness_;
};

#endif /* ADA102_RGB_H_ */