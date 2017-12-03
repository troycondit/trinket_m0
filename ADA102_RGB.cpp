/*
 * ADA102_RGB.cpp
 *
 * Created: 10/20/2017
 *  Author: Troy Condit
 */ 
 #include "ADA102_RGB.h"





 	ADA102_RGB::ADA102_RGB(Spi_bb spi_port )
	: spi_port_(spi_port)
	, red_(0)
	, green_(0)
	, blue_(0)
	, brightness_(0)
	{
		
		spi_send_color();
	}
 	void ADA102_RGB::rgbb(char red, char green, char blue, char brightness )
	{
		brightness_= brightness;
		
		red_ = red;
		green_ = green;
		blue_ = blue;

		spi_send_color();

	}
	void ADA102_RGB::rgb(uint32_t color)
	{
		red_ = (color >> 16) & 0xFF;
		green_ = (color >> 8) & 0xFF;
		blue_ = color & 0xFF;
		spi_send_color();
	}
 	void ADA102_RGB::brightness(char val) //brightness in the range of 0 31
	{
		brightness_= val;
		spi_send_color();
	}
	//
 	void ADA102_RGB::red(char val) //Red level in the range of 0 255
	{
		red_= val;
		spi_send_color();
	}
	//
 	void ADA102_RGB::green(char val) //Green level in the range of 0 255
	{
		green_= val;
		spi_send_color();
	}
	//
 	void ADA102_RGB::blue(char val) //Green level in the range of 0 255
	{
		blue_= val;
		spi_send_color();
	}

	//
	//
	//
	void ADA102_RGB::spi_send_color(void)
	{
		char start_frame[4] = {0,0,0,0};
		char end_frame[4]	= {0xFF,0xFF,0xFF,0xFF};
		char rx[4];
	
		spi_port_.tx(start_frame,rx,4);


		spi_port_.tx(0xE0 | brightness_ );//global brightness
		spi_port_.tx(blue_);//Blue
		spi_port_.tx(green_);//Green
		spi_port_.tx(red_);//RED

		spi_port_.tx(end_frame,rx,4);

	}