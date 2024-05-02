#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void add(char *name, int priority, int burst);

void printNode();
// invoke the scheduler
void schedule();

void round_robin(struct node*, int, int);
