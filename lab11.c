#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "include/myheader.h"
#include "include/array_stack.h"

#define COMMAND_BUFFER_SIZE 10

void display_startup_banner();
void stack_exerciser(const char *filename);

int main() {
  display_startup_banner();
  stack_exerciser("stack_test.txt");
}

/*
 * Function:    display_startup_banner
 * Description: Prints out the programmer's name, date and time of compilation
 * Author:      Trong Garson
 * Date:        December 3, 2018
 * Input:       None
 * Output:      None
 * Globals:     PRIME_PROGRAMMER, __DATE__ and __TIME__
 * Returns:     None
 */
void display_startup_banner (){
  printf("ARRAY STACK EXERCISER BATCH PROGRAM\n\n");
  printf("Program written by %s.\n", PRIME_PROGRAMMER);
  printf("Program compiled on %s at %s\n\n", __DATE__,__TIME__);

  return;
}

/*
 * Function:    stack_exerciser
 * Description: reads commands from filename, executes them against a stack and reports results
 * Author:      Trong Garson
 * Date:        December 3, 2018
 * Input:       filename
 * Output:      None
 * Globals:     COMMAND_BUFFER_SIZE, EXIT_FAILURE
 * Returns:     None
 */
void stack_exerciser(const char *filename) {
  FILE *test_file = fopen(filename, "r");
  if(!test_file) {
    printf("Failed to load stack_test.txt");
    exit(EXIT_FAILURE);
  }

  ArrayStack stack = stack_create();
  printf("Starting with an empty stack\n");
  printf("Reading data from file \"%s\"\n\n", filename);

  char command_buffer[COMMAND_BUFFER_SIZE];
  while(fgets(command_buffer, COMMAND_BUFFER_SIZE, test_file)){

    if(0 == strcmp(command_buffer, "display\n")) {
      stack_display(&stack);
    } else if(0 == strcmp(command_buffer, "push\n")) {
      int value;
      if(1 != fscanf(test_file, "%d\n", &value)) {
        printf("error reading value to push from test file");
        exit(EXIT_FAILURE);
      }
      if(stack_push(&stack, value)){
        printf("pushed %d on to the stack\n", value);
      } else {
        printf("could not push %d - stack is full\n", value);
      }
    } else if(0 == strcmp(command_buffer, "pop\n")) {
      int value;
      if(stack_pop(&stack, &value)) {
        printf("popped %d from the stack\n", value);
      } else {
        printf("could not pop a value - stack is empty\n");
      }
    } else {
      printf("error processing %s", command_buffer);
    }
  }
}

