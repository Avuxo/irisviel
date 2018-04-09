#define QUEUESIZE 1024
/*simple queue implementation structure*/
struct queue{
    int queue[QUEUESIZE];
    int queuePointer;
};

int peek(struct queue q);
int dequeue(struct queue q);
void enqueue(struct queue q, int value);
