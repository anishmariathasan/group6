cmake_minimum_required(VERSION 3.12)

# Pull in Pico SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(potentiometer_example_project)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

# Create and configure the project executable
add_executable(potentiometer_example
    potentiometer_example.c
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(potentiometer_example pico_stdlib hardware_adc)

# create map/bin/hex file etc.
pico_add_extra_outputs(potentiometer_example)

# enable usb output, disable uart output
pico_enable_stdio_usb(potentiometer_example 1)
pico_enable_stdio_uart(potentiometer_example 0)
