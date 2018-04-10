#define QUEUESIZE 1024
/*simple queue implementation structure*/
struct iris_queue{
    int queue[QUEUESIZE];
    int queuePointer;
};

int peek(struct iris_queue q);
int dequeue(struct iris_queue q);
void enqueue(struct iris_queue q, int value);
