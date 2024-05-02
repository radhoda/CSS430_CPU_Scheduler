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
        head->task->remainingTime = burst;

        head->next = NULL;

        curNode = head;
    }
    else {
        newNode = malloc(sizeof(struct node));
        //Pointing last node to the next newNode node
        newNode->task = malloc(sizeof(struct task));
        curNode->next = newNode;

        newNode->task->name = name;
        newNode->task->priority = priority;
        newNode->task->burst = burst;
        newNode->task->remainingTime = burst;

        newNode->next = NULL;
        curNode = newNode;
    }
}

void schedule() {
    int quantum = 10;
    int time = 0;
    int isTaskComplete = 0;

    while (!isTaskComplete) {
        isTaskComplete = 1;
        struct node *cur = head;

        while (cur != NULL) {
            if (cur->task->remainingTime > 0) {
                int slice = (cur->task->remainingTime > quantum) ? quantum : cur->task->remainingTime;
                time += cur->task->burst;
                cur->task->remainingTime -= slice;
                run(cur->task, slice,time);
                isTaskComplete = 0;
            }
            cur = cur->next;
        }
    }

}