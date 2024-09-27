#include <Wire.h>
#inlcude <LiquidCrystal_I2C.h>
#inlcude <freertos/FreeRTOS.h>
#include <freertos/task.h>

/*
	* Initialize the I2C LCD
	* Address 0x27, 16, 2
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);

/*	
	* The following definitions handle different tasks
	* We can add as many tasks as we need
*/

TaskHandle_t TimeDisplayTaskHandle;
TaskHandle_t statusDisplayTaskHandle;
TaskHandle_t GoodByeTaskHandle;


void setup() {

}
