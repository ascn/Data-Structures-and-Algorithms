/*
 * stack.c
 * 
 * Stack Abstract Data Structure
 *
 * Author: Alexander Chan <alechan@seas.upenn.edu>
 *
 * This file implements a stack data structure. This structure
 * supports two operations. First, a push, adding a value to the
 * top of the stack, and second, a pop, removing the top most element
 * and returning its value.
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Node {
    double data;
    struct Node *next;
};

struct Stack {
    struct Node *head;
};

struct Stack *create_stack() {
    struct Stack *stack = malloc (sizeof (*stack));
    stack->head = NULL;
    return stack;
}

int is_empty(struct Stack *stack) {
    if (stack->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(double x, struct Stack *stack) {
    struct Node *node = malloc (sizeof (*node));
    node->data = x;
    node->next = stack->head;
    stack->head = node;
}

double pop(struct Stack *stack) {
    struct Node *elem_to_pop = stack->head;
    stack->head = elem_to_pop->next;
    double ret_data = elem_to_pop->data;
    free(elem_to_pop);
    return ret_data;
}

struct Stack *remove_stack(struct Stack *stack) {
    while(!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
    return NULL;
}
