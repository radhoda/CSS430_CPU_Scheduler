#include "schedulers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "cpu.h"

struct node *head = NULL;
struct node *newNode = NULL;
struct node *curNode = NULL;


void add(char *name, int priority, int burst) {
    if (head == NULL) {
        head = malloc(sizeof(struct node));

        head->task = malloc(sizeof(struct task));

        head->task->name = name;
        head->task->priority = priority;
        head->task->burst = burst;

        head->next = NULL;

        curNode = head;
    }
    else {
        newNode = malloc(sizeof(struct node));
        newNode->task = malloc(sizeof(struct task));
        curNode->next = newNode;
        newNode->task->name = name;
        newNode->task->priority = priority;
        newNode->task->burst = burst;
        newNode->next = NULL;
        curNode = newNode;
    }
}

void schedule() {
    int time = 0;
    int turnAroundTime = 0;
    struct node *cur = head;

    while(cur) {
        turnAroundTime += cur->task->burst;
        run(cur->task, cur->task->burst);
        time += cur->task->burst;
        cur = cur->next;
        printf("Time is now: %d\n", time);
    }
}
