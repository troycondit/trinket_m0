/*
 * spi_bb.cpp
 *
 * Created: 12/1/2017 
 *  Author: Troy
 */ 
 #include "spi_bb.h"

 		void nop(); // default delay function;

		Spi_bb::Spi_bb( Gpio clock, Gpio mosi, Gpio miso, Gpio slave_select, bool cpol, bool cpha, void(*FN_CLOCK_DELAY)() )
				:sclk_(clock)
				,mosi_(mosi)
				,miso_(miso)
				,ss_(slave_select)
				,cpha_(cpha)
				,cpol_(cpol)
				,FN_CLOCK_DELAY_(FN_CLOCK_DELAY)
		
		{
			if(FN_CLOCK_DELAY_ == nullptr )
				FN_CLOCK_DELAY_ = nop;
		
			//set clock line to the correct idle state
			sclk_.set(cpol_);

		}
		
		//tx a single byte, returns byte received
		char Spi_bb::tx( char data )
		{
			char rx_val = 0;
			if( cpha_)
			{
				for(int inx = 8; inx  ; --inx )
				{
					mosi_.set( (data >> inx) & 1);
					rx_val += miso_.value() << inx;
					this->FN_CLOCK_DELAY_();
					sclk_.toggle();
					this->FN_CLOCK_DELAY_();
					sclk_.toggle();
				
				}
			}
			else
			{
				for(int inx = 8; inx  ; --inx )
				{
					this->FN_CLOCK_DELAY_();
					sclk_.toggle();
					this->FN_CLOCK_DELAY_();
					mosi_.set( (data >> inx) & 1);
					rx_val += miso_.value() << inx;
					sclk_.toggle();
				}
			}

			return rx_val;
		}
		//tx_buff and rx_buff many bytes, both buffers must be at as big as size
		void Spi_bb::tx( char * const tx_buff, char * rx_buff, int size )
		{
			for(int inx = 0; inx < size; inx ++)
				rx_buff[inx] = this->tx(tx_buff[inx]);
		}
		//
		//
		//
		void nop()
		{
			__NOP();
		}