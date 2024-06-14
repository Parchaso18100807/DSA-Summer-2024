#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "QueueLL.h"

int main(int argc, char *argv[]) {
	
	Queue QL;
	
	initQueue(&QL);
	
	Enqueue(&QL, 10);
	Enqueue(&QL, 20);
	Enqueue(&QL, 30);
	
	displayQueue(QL);
	
	printf("\n=====\n");
	
	Dequeue(&QL);
	
	displayQueue(QL);
	
	printf("\n=====\n");
	
	Enqueue(&QL, 40);
	
	displayQueue(QL);
	
	printf("\n=====\n");
	
	Dequeue(&QL);
	
	displayQueue(QL);
	
	return 0;
}
