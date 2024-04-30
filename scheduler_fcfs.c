#include "schedulers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

struct node *head = NULL;
struct node *newNode = NULL;
struct node *curNode = NULL;


void add(char *name, int priority, int burst) {
    if (head == NULL) {
        head = malloc(sizeof(struct node));

        head->task->name = name;
        head->task->priority = priority;
        head->task->burst = burst;

        head->next = NULL;

        curNode = head;
    }
    else {
        newNode = malloc(sizeof(struct node));
        //Pointing last node to the next newNode node
        curNode->next = newNode;

        newNode->task->name = name;
        newNode->task->priority = priority;
        newNode->task->burst = burst;
        newNode->next = NULL;
        curNode = newNode;
    }
}

void print() {
    printf("%s", curNode->task->name);
}