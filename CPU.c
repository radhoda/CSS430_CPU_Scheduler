/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>

#include "cpu.h"

// run this task for the specified time slice
void run(Task *task, int slice, int totalTime) {
    printf("Running task = [%s] [%d] [%d] for %d units. Start = %d\n",task->name, task->priority, task->burst, slice, totalTime);
}
