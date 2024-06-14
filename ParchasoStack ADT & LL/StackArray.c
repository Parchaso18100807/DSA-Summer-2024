#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}

StackArrayList createStack(){
	StackArrayList stack;
	stack.top = -1;
	return stack;
}

bool isEmpty(StackArrayList s){
	
	if(s.top == -1){
		return true;
	}
}

bool isFull(StackArrayList s){
	
	if(s.top >= MAX){
		return true;
	}
}

bool stack_push(StackArrayList *s, int elem){
//	if(isFull()) return FALSE;
//
//	// Increment top index
//	top++;
//	// Add the item to the Stack
//	theStack[top] = ch;
//	return TRUE;

	if(s->top != 0){
		s->top--;
		s->data[s->top] = elem;
		return true;
	}
}

bool stack_pop(StackArrayList *s){
//	if(s->)
//	
//	return
}
int stack_peek(StackArrayList s){
	
	
}

void display(StackArrayList s){
	
	
}

void visualize(StackArrayList s){
	
	
}
