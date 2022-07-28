#include "driver/gpio.h"

#include "constants.c"
#include "server.c"
#include "hotspot.c"

void setupPints()
{
    // GPIO

    gpio_config_t io_conf;
    // disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    // set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    // bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    // disable pull-down mode
    io_conf.pull_down_en = 0;
    // disable pull-up mode
    io_conf.pull_up_en = 0;
    // configure GPIO with the given settings
    gpio_config(&io_conf);

    gpio_set_level(GPIO_OUTPUT_IO_2, 0);

    // ADC

    adc_config_t adc_conf;
    adc_conf.mode = ADC_READ_TOUT_MODE;
    adc_conf.clk_div = 8;

    adc_init(&adc_conf);
}

void app_main(void)
{
    setupPints();
    launchSoftAp();
    while (1)
        vTaskDelay(10);
}