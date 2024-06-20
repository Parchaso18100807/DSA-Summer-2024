#ifndef FCFS
#define FCFS

typedef struct node {
	char process;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnAroundTime;
    float avgWaitTime;
    float avgTurnAroundTime;
    struct node* next;
}fcfsNode, *fcfsPtr;

typedef struct {
    fcfsPtr front;
    fcfsPtr rear;
}Queue;

void initQueue(Queue* q);

void displayFCFS(Queue q);

#endif
