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
    // 1 - If head is NULL
    if (head == NULL) {
        head = malloc(sizeof(struct node));
        head->task = malloc(sizeof(struct task));

        head->task->name = name;
        head->task->priority = priority;
        head->task->burst = burst;

        head->next = NULL;
    }
        // 2 - Head exists
    else {
        newNode = malloc(sizeof(struct node));
        newNode->task = malloc(sizeof(struct task));
        newNode->task->name = name;
        newNode->task->priority = priority;
        newNode->task->burst = burst;

        newNode->next = NULL;
        // 3 - Head to be replaced with new node
        if (head->task->priority > newNode->task->priority) {
            newNode->next = head;
            head = newNode;
        }
            // 4 - Not head, some node down the linked list
        else {
            curNode = head;
            while (curNode->next != NULL && curNode->next->task->priority <= newNode->task->priority) {
                curNode = curNode->next;
            }
            newNode->next = curNode->next;
            curNode->next = newNode;
        }
    }
}

void schedule() {

}