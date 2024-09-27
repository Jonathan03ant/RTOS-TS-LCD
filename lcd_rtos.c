#include <Wire.h>
#inlcude <LiquidCrystal_I2C.h>
#inlcude <freertos/FreeRTOS.h>
#include <freertos/task.h>

/*
	* Initialize the I2C LCD
	* Address 0x27, 16, 2
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {

}
