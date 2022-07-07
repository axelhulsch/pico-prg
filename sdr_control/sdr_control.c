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

    const uint BAND_1_IN_PIN = 5;
    gpio_init(BAND_1_IN_PIN);
    gpio_set_dir(BAND_1_IN_PIN, GPIO_IN);

    const uint BAND_2_IN_PIN = 4;
    gpio_init(BAND_2_IN_PIN);
    gpio_set_dir(BAND_2_IN_PIN, GPIO_IN);

    const uint BAND_4_IN_PIN = 3;
    gpio_init(BAND_4_IN_PIN);
    gpio_set_dir(BAND_4_IN_PIN, GPIO_IN);

    const uint BAND_8_IN_PIN = 2;
    gpio_init(BAND_8_IN_PIN);
    gpio_set_dir(BAND_8_IN_PIN, GPIO_IN);


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

        int b1= gpio_get(BAND_1_IN_PIN);
        int b2= gpio_get(BAND_2_IN_PIN);
        int b4= gpio_get(BAND_4_IN_PIN);
        int b8= gpio_get(BAND_8_IN_PIN);
        int band = b1+b2*2+b4*4+b8*8;

        switch (band){
            case 2: //80m
            case 3: //60m
            case 4: //40m
            case 5: //30m
            case 6: //20m
            case 7: //17m
            case 8: //15m
            case 9: //12m
            case 10: //10m
                gpio_put(PTT_OUT_PIN, ptt);
                gpio_put(PTT_RELAIS_OUT_PIN,ptt==false);
                break;
            case 1: //160m
            case 11: //6m
            default: 
                gpio_put(PTT_OUT_PIN, false);
                gpio_put(PTT_RELAIS_OUT_PIN,true);
        }
        switch (band){
            case 1: //160m
            case 2: //80m
                gpio_put(DG6_OUT_PIN, true);
                gpio_put(DG5_OUT_PIN, true);
                gpio_put(DG4_OUT_PIN, false);
                gpio_put(DG3_OUT_PIN, false);
                gpio_put(DG2_OUT_PIN, true);
                gpio_put(DG1_OUT_PIN, true);
                break;
            case 3: //60m
                gpio_put(DG6_OUT_PIN, true);
                gpio_put(DG5_OUT_PIN, true);
                gpio_put(DG4_OUT_PIN, false);
                gpio_put(DG3_OUT_PIN, false);
                gpio_put(DG2_OUT_PIN, false);
                gpio_put(DG1_OUT_PIN, false);
                break;
            case 4: //40m
                gpio_put(DG6_OUT_PIN, true);
                gpio_put(DG5_OUT_PIN, false);
                gpio_put(DG4_OUT_PIN, true);
                gpio_put(DG3_OUT_PIN, true);
                gpio_put(DG2_OUT_PIN, true);
                gpio_put(DG1_OUT_PIN, true);
                break;
            case 5: //30m
                gpio_put(DG6_OUT_PIN, true);
                gpio_put(DG5_OUT_PIN, false);
                gpio_put(DG4_OUT_PIN, true);
                gpio_put(DG3_OUT_PIN, true);
                gpio_put(DG2_OUT_PIN, false);
                gpio_put(DG1_OUT_PIN, false);
                break;
            case 6: //20m
                gpio_put(DG6_OUT_PIN, true);
                gpio_put(DG5_OUT_PIN, false);
                gpio_put(DG4_OUT_PIN, false);
                gpio_put(DG3_OUT_PIN, false);
                gpio_put(DG2_OUT_PIN, false);
                gpio_put(DG1_OUT_PIN, true);
                break;
            case 7: //17m
            case 8: //15m
            case 9: //12m
                gpio_put(DG6_OUT_PIN, false);
                gpio_put(DG5_OUT_PIN, false);
                gpio_put(DG4_OUT_PIN, true);
                gpio_put(DG3_OUT_PIN, true);
                gpio_put(DG2_OUT_PIN, true);
                gpio_put(DG1_OUT_PIN, true);
                break;
            case 10: //10m
            case 11: //6m
            default: 
                gpio_put(DG6_OUT_PIN, false);
                gpio_put(DG5_OUT_PIN, false);
                gpio_put(DG4_OUT_PIN, true);
                gpio_put(DG3_OUT_PIN, true);
                gpio_put(DG2_OUT_PIN, false);
                gpio_put(DG1_OUT_PIN, true);
        }
        switch (band){
            case 1: //160m
            case 2: //80m
            case 3: //60m
            case 4: //40m
            case 5: //30m
                gpio_put(LP30M_OUT_PIN, true);
                gpio_put(LP15M_OUT_PIN, false);
                gpio_put(LP10M_OUT_PIN, false);
                break;
            case 6: //20m
            case 7: //17m
            case 8: //15m
                gpio_put(LP15M_OUT_PIN, true);
                gpio_put(LP30M_OUT_PIN, false);
                gpio_put(LP10M_OUT_PIN, false);
                break;
            case 9: //12m
            case 10: //10m
                gpio_put(LP10M_OUT_PIN, true);
                gpio_put(LP15M_OUT_PIN, false);
                gpio_put(LP30M_OUT_PIN, false);
                break;
            case 11: //6m
            default: 
                gpio_put(LP10M_OUT_PIN, true);
        }




    }
}