/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "math.h"
#include "pico/double.h"
#include "pico/util/queue.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/multicore.h"

bool timer_callback(repeating_timer_t *rt);

uint slice_num;
double Winkel = 0.0;
mutex_t mutex;
int main() {
    mutex_init(&mutex);
    stdio_init_all();

    uart_init(uart0,115200);
    gpio_set_function(0,GPIO_FUNC_UART);
    gpio_set_function(1,GPIO_FUNC_UART);

    adc_init();

    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    adc_gpio_init(27);
    adc_gpio_init(28);
    adc_gpio_init(29);
    
    gpio_set_function(15, GPIO_FUNC_PWM);

    // Find out which PWM slice is connected to GPIO 0 (it's slice 0)
    slice_num = pwm_gpio_to_slice_num(15);

    // Set period of 4 cycles (0 to 3 inclusive)
    pwm_set_wrap(slice_num, 250);
    // Set channel A output high for one cycle before dropping
    // Set the PWM running
    pwm_set_enabled(slice_num, true);
    /// \end::setup_pwm[]
   
    int hz = 15000;

    repeating_timer_t timer;

    // negative timeout means exact delay (rather than delay between callbacks)
    if (!add_repeating_timer_us(-2000, timer_callback, NULL, &timer)) {
        printf("Failed to add timer\n");
        return 1;
    }

    while (1)
   {
       char c=uart_getc(uart0);
       mutex_enter_blocking(&mutex);
       switch (c)
       {
       case 'D':
           /* code */
           printf("huhu\n");
           break;
       
       default:
           break;
       } 
       mutex_exit(&mutex);
   } 
    cancel_repeating_timer(&timer);
    printf("Done\n");
}

double sumsquaredx = 0.0;
double sumsquaredy = 0.0;
double sumdx = 0.0;
double sumdy = 0.0;
int i = 0;
int p = 0;
int w = 0;
double x = 0.0;
double y = 0.0;
double offsetx = 0.0;
double offsety = 0.0;
int timeoffset=9;
bool timer_callback(repeating_timer_t *rt) 
{
    adc_select_input(0);
    double dx = adc_read();
    adc_select_input(1);
    double dy = adc_read();
 
    double sy;
    sy = (sin(2 * M_PI * i / 10) * 120) + 120; //120
    pwm_set_gpio_level(15,sy);
    i++;
    return true; // keep repeating
}
