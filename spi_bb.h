/*
 * spi_bb.h
 *
 * Created: 12/1/2017 8:37:19 PM
 *  Author: Troy
 * 
 */ 


#ifndef SPI_BB_H_
#define SPI_BB_H_

#include "gpio.h"

//Bit Bang SPI implementation
class Spi_bb
{
	public:
		// cpol = clock polarity;  1 = idle high, 0 = idle low
		// cpha = clock phase; 1 = data sampled on the leading clock transition,  0 data sampled on the traling clock transistion
		// FN_CLOCK_DELAY  pointer to a delay function
		Spi_bb( Gpio clock, Gpio mosi, Gpio miso, Gpio slave_select, bool cpol = 1, bool cpha  = 1, void(*FN_CLOCK_DELAY)() = nullptr );
		
		//tx a single byte, returns byte received
		char tx( char value );
		//tx and rx many bytes, both buffers must be at as big as size
		void tx( char * const tx, char * rx, int size ); 

		private:
		Gpio sclk_;
		Gpio mosi_;
		Gpio miso_;
		Gpio ss_;
		bool cpha_;
		bool cpol_;
		void(*FN_CLOCK_DELAY_)();


};



#endif /* SPI_BB_H_ */