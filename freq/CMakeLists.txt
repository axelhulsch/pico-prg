if (NOT PICO_TIME_NO_ALARM_SUPPORT)
    add_executable(freq
            freq.c
            )

    # Pull in our (to be renamed) simple get you started dependencies
    target_link_libraries(freq pico_stdlib pico_multicore hardware_adc hardware_pwm)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(freq 0)
    pico_enable_stdio_uart(freq 1)
   
    # create map/bin/hex file etc.
    pico_add_extra_outputs(freq)

    # add url via pico_set_program_url
    #auto_set_url(freq)
endif()
