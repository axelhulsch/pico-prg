/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);


    const uint PTT_PIN = 6;//GP6
    gpio_init(PTT_PIN);
    gpio_set_dir(PTT_PIN, GPIO_IN);
    
    const uint PTT_OUT_PIN = 15;//GP15
    gpio_init(PTT_OUT_PIN);
    gpio_set_dir(PTT_OUT_PIN, GPIO_OUT);
    
    const uint PTT_RELAIS_OUT_PIN = 28;//GP28
    gpio_init(PTT_RELAIS_OUT_PIN);
    gpio_set_dir(PTT_RELAIS_OUT_PIN, GPIO_OUT);

    const uint DG1_OUT_PIN = 16;
    gpio_init(DG1_OUT_PIN);
    gpio_set_dir(DG1_OUT_PIN, GPIO_OUT);

    const uint DG2_OUT_PIN = 17;
    gpio_init(DG2_OUT_PIN);
    gpio_set_dir(DG2_OUT_PIN, GPIO_OUT);

    const uint DG3_OUT_PIN = 18;
    gpio_init(DG3_OUT_PIN);
    gpio_set_dir(DG3_OUT_PIN, GPIO_OUT);

    const uint DG4_OUT_PIN = 19;
    gpio_init(DG4_OUT_PIN);
    gpio_set_dir(DG1_OUT_PIN, GPIO_OUT);

    const uint DG5_OUT_PIN = 20;
    gpio_init(DG5_OUT_PIN);
    gpio_set_dir(DG5_OUT_PIN, GPIO_OUT);

    const uint DG6_OUT_PIN = 21;
    gpio_init(DG6_OUT_PIN);
    gpio_set_dir(DG6_OUT_PIN, GPIO_OUT);


    const uint LP10M_OUT_PIN = 8;
    gpio_init(LP10M_OUT_PIN);
    gpio_set_dir(LP10M_OUT_PIN, GPIO_OUT);

    const uint LP15M_OUT_PIN = 9;
    gpio_init(LP15M_OUT_PIN);
    gpio_set_dir(LP15M_OUT_PIN, GPIO_OUT);

    const uint LP30M_OUT_PIN = 10;
    gpio_init(LP30M_OUT_PIN);
    gpio_set_dir(LP30M_OUT_PIN, GPIO_OUT);


  
    while (true) {
        bool ptt;
        ptt=gpio_get(PTT_PIN);
        gpio_put(LED_PIN, ptt);
        gpio_put(PTT_OUT_PIN, ptt);
        gpio_put(PTT_RELAIS_OUT_PIN,ptt==false);

        gpio_put(DG6_OUT_PIN, true);
        gpio_put(DG5_OUT_PIN, false);
        gpio_put(DG4_OUT_PIN, false);
        gpio_put(DG3_OUT_PIN, false);
        gpio_put(DG2_OUT_PIN, false);
        gpio_put(DG1_OUT_PIN, true);

        gpio_put(LP15M_OUT_PIN, true);


    }
}