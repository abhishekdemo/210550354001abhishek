#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timer.h"



TaskHandle_t pressure_handle;
TaskHandle_t temprature_handle;
TaskHandle_t motion_handle;ll

void pressure_task(void * data)
    while (1)
    {
        printf("presure started=%d\n",portTICK_PERIOD_MS);
        
        printf("presure endede\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}       

void temprature_task(void * data)
{
    while (1)
    {
        printf("temprature started=%d\n",portTICK_PERIOD_MS);
        printf("temprature ended=%d\n",portTICK_PERIOD_MS);
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        vTaskDelete(pressure_handle);
        vTaskDelete(NULL);
    }
}

void motion_task(void * data)
{
    while(1)
    {
        printf("motin_task=%d\n",portTICK_PERIOD_MS);
           vTaskDelay(5000 / portTICK_PERIOD_MS);
        printf("motion end"=%d\n, portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    int i = 0;
    xTaskCreate(pressure_task, "presstask",2048,NULL,1,NULL,&pressure_task);
    xTaskCreate(temprature_task,"pretalk",2048,NULL,2,NULL,&temprature_task);
    xTaskCreate(motion_task,"motion_talk",2048,NULL,5,NULL,&motion_task);
    while (1) {
        printf("[%d] Hello world!\n", i);
        i++;
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}

