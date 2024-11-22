#include <stdio.h>
#include "pico/stdlib.h"
#include "utils/logger.h"



int main()
{
    printf("Initializing...\n");
    
    stdio_init_all();

    while (true) {
        int door_state = get_door_state();
        if (door_state == 1) {
            printf("Door is open\n");
        } else {
            printf("Door is closed\n");
        }
        sleep_ms(1000);
    }
}

int get_door_state() {
    return 0;
}
