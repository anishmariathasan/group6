#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {
    // Initialize stdio and wait for USB connection for serial output
    stdio_init_all();
    while (!stdio_usb_connected()) {
        sleep_ms(250); // Sleep for USB connection
    }

    printf("Potentiometer Reading Started\n");

    // Initialize ADC
    adc_init();
    
    // Select ADC input (ADC0 is GPIO26 on Pi Pico)
    adc_select_input(0);

    while (1) {
        // Read from ADC, 12-bit conversion, ranges from 0 to 4095
        uint16_t result = adc_read();
        
        // Convert ADC value to voltage, assuming a 3.3V reference
        float voltage = result * 3.3f / 4095.0f;

        printf("Potentiometer Voltage: %.2f V\n", voltage);
        
        sleep_ms(1000); // Sleep for a bit to avoid spamming
    }

    return 0;
}
