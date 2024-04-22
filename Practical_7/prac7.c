#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear =-1;

// Check if the queue is full
int isFull() {
    if((front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    if(front == -1) return 1;
    return 0;
}

// Add elements into queue
void enqueue(int element) {
    if(isFull()) printf("Queue is full!! \n");
    else {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("Inserted -> %d\n", element);
    }
}

// Remove element from queue
int dequeue() {
    int element;
    if(isEmpty()) {
        printf("Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after deleting it. */
        else {
            front = (front + 1) % SIZE;
            
        }
        printf("Deleted element -> %d \n", element);
        return(element);
    }
}

void display() {
    int i;
    if(isEmpty()) printf("Empty Queue\n");
    else {
        printf("Queue Elements: ");
        for(i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d \t",items[i]);
        }
        printf("%d \n",items[i]);
    }
}

int main() {
    // Fails because front = -1 
    dequeue();
    
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    
    // Display the queue
    display();
    
    // Fails to enqueue because front == 0 && rear == SIZE - 1
    enqueue(6);
    
    dequeue();
    
    // Enqueue 7 at the end of queue
    enqueue(7);
    
    // Display the queue
    display();
    
    dequeue();
    
    return 0;
}