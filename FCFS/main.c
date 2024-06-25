#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

int main(int argc, char *argv[]) {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, 'A', 5, 0);
    enqueue(&q, 'B', 3, 2);
    enqueue(&q, 'C', 6, 4);
    
    calculateMetrics(&q);
    
    displayFCFS(q);
    
    return 0;
}

