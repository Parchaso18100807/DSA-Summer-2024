#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, char process, int burstTime, int arrivalTime) {
    fcfsPtr newNode = (fcfsPtr)malloc(sizeof(fcfsNode));
    if(newNode != NULL) {
	    newNode->process = process;
	    newNode->burstTime = burstTime;
	    newNode->arrivalTime = arrivalTime;
	    newNode->waitingTime = 0;  
	    newNode->turnAroundTime = 0;  
	    newNode->avgWaitTime = 0.0;  
	    newNode->avgTurnAroundTime = 0.0;
	    newNode->endTime = 0;
	    newNode->next = NULL;
	    
	    newNode->endTime = newNode->arrivalTime + newNode->burstTime;
	    
	    if(q->rear == NULL) {
	        q->front = newNode;
	        q->rear = newNode;
	    }else {
	        q->rear->next = newNode;
	        q->rear = newNode;
	    }
    }
}

void dequeue(Queue* q) {
    if(q->front != NULL) {
	    fcfsPtr temp = q->front;
	    q->front = q->front->next;
	    if(q->front == NULL) {
	        q->rear = NULL;
	    }
	    free(temp);
    }
}

fcfsPtr front(Queue q) {
    return q.front;
}

fcfsPtr rear(Queue q) {
    return q.rear;
}

int isEmpty(Queue q) {
    return (q.front == NULL);
}

void calculateMetrics(Queue* q) {
	fcfsPtr current;
	int totalWaitingTime = 0;
	int totalTurnAroundTime = 0;
	int numProcesses = 0;
	
    if(!isEmpty(*q)) {
	    for(current=q->front; current != NULL; current = current->next){
	        current->waitingTime = totalWaitingTime;
	        current->turnAroundTime = current->waitingTime + current->burstTime;
	        totalWaitingTime += current->burstTime;
	        totalTurnAroundTime += current->turnAroundTime;
	        numProcesses++;
	    }
	    
	    float avgWaitTime = (float)totalWaitingTime / numProcesses;
	    float avgTurnAroundTime = (float)totalTurnAroundTime / numProcesses;
	    
	    for(current=q->front; current != NULL; current = current->next){
	        current->avgWaitTime = avgWaitTime;
	        current->avgTurnAroundTime = avgTurnAroundTime;
	    }
    }
}

void displayFCFS(Queue q) {
    fcfsPtr current;
    if(q.front != NULL) {
        printf("FCFS Queue:\n");
        printf("Process\tBurst Time\tArrival Time\tEnd Time\tWaiting Time\tTurnaround Time\n");
        printf("--------------------------------------------------------------------------\n");
        
        for(current=q.front; current != NULL; current = current->next){
            printf("%c\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", current->process, current->burstTime, current->arrivalTime, current->endTime, current->waitingTime, current->turnAroundTime);
        }
        
        printf("\nAverage Metrics:\n");
        printf("Average Waiting Time: %.2f\n", q.front->avgWaitTime);
        printf("Average Turnaround Time: %.2f\n", q.front->avgTurnAroundTime);
    }
}


