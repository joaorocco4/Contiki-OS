#include "contiki.h"
#include <stdio.h>

PROCESS(processo1, "exemplo");
AUTOSTART_PROCESSES(&processo1);

PROCESS_THREAD(processo1, ev, data)
{
    static struct etimer timer;

    PROCESS_BEGIN();
    etimer_set(&timer, 1 * CLOCK_SECOND);

    while (1) {
        printf("Projeto\n");
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
        etimer_reset(&timer);
    }

    PROCESS_END();
}
