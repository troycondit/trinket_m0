/*
 * TrinketM0.cpp
 *
 * Created: 11/30/2017 7:42:48 PM
 * Author : Troy
 */ 


#include "sam.h"
#include "gpio.h"
#include "led.h"
#include "spi_bb.h"
#include "ADA102_RGB.h"

#define LED_PIN = PIN_PA10;


 // Forget about it this is no where close to being accurate
 static void delay_nops(int us)
 {
	 volatile int val = 0;
	 for(; val < us; val++ )
	 for(int inx; inx < 10; inx++ )
	 __NOP();
 }

 void spi_delay()
 {	
 delay_nops(4);
 }

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

	//Gpio led_pin(PIN_PA10);
	Led led(Gpio(PIN_PA10));


	led.on();
	led.off(); 
	led.toggle();

	Gpio spi_clk(PIN_PA01, 0, Gpio::OUT );
	Gpio spi_mosi(PIN_PA00, 0, Gpio::OUT );
	Gpio spi_miso(PIN_NULL, 0, Gpio::IN );
	Gpio spi_ss(PIN_NULL, 0, Gpio::OUT);

	Spi_bb spi_dev(spi_clk,spi_mosi,spi_miso,spi_ss,1,1,spi_delay);

	ADA102_RGB rgb(spi_dev);//RAII led will get turned off!
	rgb.brightness(2);
	//rgb.green(100);
	rgb.blue(3);
	//rgb.red(70);

    /* Replace with your application code */
    while (1) 
    {
		for(uint32_t inx = 0; inx < 0xFFFFFF; inx++ )
		{
			rgb.rgb(inx);
			led.set( !led.isOn() );
		}
    }
}
