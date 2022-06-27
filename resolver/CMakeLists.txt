if (NOT PICO_TIME_NO_ALARM_SUPPORT)
    add_executable(resolver
            resolver.c
            )

    # Pull in our (to be renamed) simple get you started dependencies
    target_link_libraries(resolver pico_stdlib pico_multicore hardware_adc hardware_pwm)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(resolver 0)
    pico_enable_stdio_uart(resolver 1)
   
    # create map/bin/hex file etc.
    pico_add_extra_outputs(resolver)

    # add url via pico_set_program_url
    #auto_set_url(resolver)
endif()
