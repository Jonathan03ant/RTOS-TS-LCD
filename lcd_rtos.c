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
TaskHandle_t StatusDisplayTaskHandle;
TaskHandle_t GoodByeTaskHandle;

/*
	* TASK 1, Display time
*/
void vDisplayTimeTask(void* pvParameters){
	while (1) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Time: 12:34");  // Example time 
        vTaskDelay(pdMS_TO_TICKS(5000));  // Wait for 5 seconds
        
        // Switch to status display task after time
        vTaskResume(StatusDisplayTaskHandle); 
        vTaskSuspend(NULL);  // Suspend this task
    }
}


/*
	* TASK 2, Display status
*/
void vDisplayStatusTask(void* pvParameters) {
	while (1) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Status: OK");
        vTaskDelay(pdMS_TO_TICKS(5000));  // Wait for 5 seconds
        
        // Switch to Goodbye task
        vTaskResume(GoodbyeTaskHandle);  
        vTaskSuspend(NULL);  // Suspend this task
    }

}

/*
	* TASK 3, Display Goodbye 
*/
void vGoodByeTask(void* pvParameters){

}


/*
	* Flow setup here
*/

void setup() {

}


