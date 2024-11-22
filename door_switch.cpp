#include <stdio.h>
#include "pico/stdlib.h"
#include "utils/logger.h"



int get_door_state() {
    return 0;
}

int main()
{
    printf("Initializing...\n");
    
    stdio_init_all();
    Logger* logger = Logger::getInstance();

    while (true) {
        int door_state = get_door_state();

        if (door_state == 1) {
            logger->info({"Door is open", {{"door_state", "open"}}});
        } else {
            logger->info({"Door is closed", {{"door_state", "closed"}}});
        }
        sleep_ms(3000);
    }
}

