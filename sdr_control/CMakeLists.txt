add_executable(sdr_control
        sdr_control.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(sdr_control pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(sdr_control)

# add url via pico_set_program_url
#auto_set_url(sdr_control)