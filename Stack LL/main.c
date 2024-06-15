#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"

int main() {
    StackLinkedList stack = createStack();

    stack_push(&stack, 10);
    stack_push(&stack, 25);
    stack_push(&stack, 30);
    stack_push(&stack, 45);
    stack_push(&stack, 50);
    display(stack);
    visualize(stack);

    printf("Top element: %d\n\n", stack_peek(stack));

    stack_pop(&stack);
    stack_pop(&stack);
    display(stack);
    visualize(stack);
    printf("Top element: %d\n\n", stack_peek(stack));

    StackLinkedList evenStack = getEven(&stack);
    printf("Even elements in a new stack: ");
    display(evenStack);
    visualize(evenStack);

    return 0;
}

