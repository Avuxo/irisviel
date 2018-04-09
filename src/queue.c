#include <string.h>
#include "iris-log.h"
#include "queue.h"

int peek(struct queue q){
    if(q.queuePointer > 0)
        return q.queue[q.queuePointer];
    iris_fatalError("Stack is empty");
    return 0; /*return is never reached due to exit 0.
                This dead code exists because of the no-return-type 
                compiler warning*/
}

int dequeue(struct queue q){
    if(q.queuePointer > 0)
        return q.queue[q.queuePointer--];
    iris_fatalError("Queue underflow.");
    return 0;
}

void enqueue(struct queue q, int value){
    if(q.queuePointer > QUEUESIZE)
        iris_fatalError("Queue overflow.");
    q.queue[q.queuePointer++] = value;
}
