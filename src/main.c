#include "driver/gpio.h"
#include "driver/adc.h"
#include <stdio.h>

#define LED 2
#define mask_out (1 << LED)

void app_main(){

gpio_config_t GPIOconfig;

GPIOconfig.mode = GPIO_MODE_OUTPUT;
GPIOconfig.intr_type = 0;
GPIOconfig.pull_down_en = 0;
GPIOconfig.pull_up_en = 0;
GPIOconfig.pin_bit_mask = mask_out;

gpio_config(&GPIOconfig);

adc1_config_width(ADC_WIDTH_9Bit);
adc1_config_channel_atten(ADC_CHANNEL_0,ADC_ATTEN_0db);
int value;
while (1){
 value = adc1_get_raw(ADC_CHANNEL_0);
 if(value <= 250){
     gpio_set_level(LED,0);
 }else{
     gpio_set_level(LED,1);
 }
}


}