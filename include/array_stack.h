#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#define STACK_SIZE 100

typedef struct {
  int top;
  int values[STACK_SIZE];
} ArrayStack;

ArrayStack stack_create();
int stack_push(ArrayStack *stack, int value);
int stack_pop(ArrayStack *stack, int *value);
void stack_display(ArrayStack *stack);

#endif
