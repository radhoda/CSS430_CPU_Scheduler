
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *head = NULL;
struct node *newNode = NULL;
struct node *current = NULL;
struct node *curNode = NULL;



void add(char *name, int priority, int burst) {
    if (head == NULL) {
        head = malloc(sizeof(struct node));
        head->task = malloc(sizeof(struct task));

        head->task->name = name;
        head->task->priority = priority;
        head->task->burst = burst;

        head->next = NULL;
    }
    else {
        newNode = malloc(sizeof(struct node));
        newNode->task = malloc(sizeof(struct task));
        newNode->task->name = name;
        newNode->task->priority = priority;
        newNode->task->burst = burst;

        newNode->next = NULL;
        if (head->task->priority > newNode->task->priority) {
            newNode->next = head;
            head = newNode;
        }
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
    current = head;
    struct node *tempNode = head;
    struct node *beginning = malloc(sizeof(struct node));
    int newBurst = 0;
    int time = 0;
    while (tempNode != NULL) {

        if (tempNode->next == NULL) {
            run(tempNode->task, tempNode->task->burst);
            time += tempNode->task->burst;
            printf("Time is now: %d\n", time);
            break;
        }
        else {
            if ((tempNode->task->priority != tempNode->next->task->priority)) {

                run(tempNode->task, tempNode->task->burst);
                time += tempNode->task->burst;
                printf("Time is now: %d\n", time);
                tempNode = tempNode->next;
            }
            else {
                if (tempNode->next != NULL) {
                    if (tempNode->task->priority == tempNode->next->task->priority) {

                        current = tempNode ;
                        while (current->next != NULL) {
                            current = current->next;
                            if (current->task->priority != current->next->task->priority) {
                                beginning = current->next;
                                current->next = NULL;
                                current = tempNode;
                                break;
                            }
                            else {
                            }
                        }
                        while (tempNode != NULL   ) {
                            if (tempNode->task->burst >= 10) {
                                newBurst = tempNode->task->burst - 10;
                                tempNode->task->burst = 10;
                                run(tempNode->task, 10);
                                time += 10;
                                printf("Time is now: %d\n", time);
                            }
                            else if (tempNode-> task-> burst < 10) {
                                newBurst = 0;
                                run(tempNode->task, tempNode->task->burst);
                                time += tempNode->task->burst;
                                printf("Time is now: %d\n", time);
                            }
                            while(1) {
                                if (current->next !=NULL) {
                                    current = current->next;
                                    if (current->next == NULL) {
                                        if (newBurst != 0) {
                                            struct node * newnode = malloc(sizeof(struct node));
                                            newnode->task = malloc(sizeof(struct task));
                                            newnode->task->name = tempNode->task->name ;
                                            newnode->task->burst = newBurst;
                                            newnode->task->priority = tempNode->task->priority;
                                            tempNode = tempNode->next ;
                                            current->next = newnode;
                                            newnode->next = NULL;
                                            current = tempNode;
                                            break;
                                        }
                                        else if (newBurst == 0) {
                                            tempNode = tempNode->next;
                                            current = tempNode;
                                            break;
                                        }
                                    }
                                }
                                else { // if this is the last element
                                    tempNode = tempNode->next; // tempNode == NULL after this
                                    current = beginning;
                                    break;
                                }
                            }
                        }
                        tempNode = beginning;
                    }
                }
            }
        }
    }
}



