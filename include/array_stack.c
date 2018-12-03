#include <stdio.h>
#include "array_stack.h"

/*
 * Function:    stack_create
 * Description: creates and initializes a stack 
 * Author:      Trong Garson
 * Date:        December 3, 2018
 * Input:       None
 * Output:      None
 * Globals:     None
 * Returns:     An empty stack
 */
ArrayStack stack_create() {
  // initialize a new stack with top -1 and a 0 initialized array
  ArrayStack s = { -1, {0} };
  return s;
}

/*
 * Function:    stack_push
 * Description: pushes a value onto the stack
 * Author:      Trong Garson
 * Date:        December 3, 2018
 * Input:       stack, value
 * Output:      stack
 * Globals:     STACK_SIZE
 * Returns:     success(1) or failure(0)
 */
int stack_push(ArrayStack *stack, int value){
  if(stack->top < STACK_SIZE -1) {
    stack->top++;
    stack->values[stack->top] = value;
    return 1;
  } else {
    return 0;
  }
}

/*
 * Function:    stack_pop
 * Description: pops the top value from the stack
 * Author:      Trong Garson
 * Date:        December 3, 2018
 * Input:       stack 
 * Output:      stack, value
 * Globals:     None
 * Returns:     success(1) or failure(0)
 */
int stack_pop(ArrayStack *stack, int *value) {
  if(stack->top >= 0) {
    stack->top--;
    *value = stack->values[stack->top + 1];
    return 1;
  } else {
    return 0;
  }
}

/*
 * Function:    stack_display
 * Description: prints the elements in the stack from top to bottom
 * Author:      Trong Garson
 * Date:        December 3, 2018
 * Input:       stack 
 * Output:      None
 * Globals:     None
 * Returns:     None
 */
void stack_display(ArrayStack *stack){
  int i;
  if(stack->top < 0) {
    printf("* the stack is empty *\n");
    return;
  }
  for(i = stack->top; i >= 0; i--) {
    printf("%d ", stack->values[i]);
  }
  printf("\n");
}
