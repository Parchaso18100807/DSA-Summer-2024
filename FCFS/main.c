#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

int main(int argc, char *argv[]) {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, 'A', 5, 5);
    enqueue(&q, 'B', 2, 4);
    enqueue(&q, 'C', 7, 0);
    enqueue(&q, 'D', 3, 2);
    
//    displayFCFS(q);
//    
//    dequeue(&q);
    
    calculateMetrics(&q);
    
    displayFCFS(q);
    
    return 0;
}

