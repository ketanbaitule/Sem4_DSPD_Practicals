#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void display(struct Node * stack){
    struct Node * temp = stack;
    printf("Stack Elements are:\t");
    if(temp == NULL){
        printf("Empty Stack");
    }
    while (temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(struct Node ** stack, int data){
    struct Node * tempNode = (struct Node *) malloc (sizeof(struct Node));
    tempNode -> data = data;
    tempNode -> next = *stack;
    *stack = tempNode;
}

int pop(struct Node ** stack){
    if(*stack == NULL)
        return -1;
    int popped_elem = (*stack)->data;
    *stack = (*stack) -> next;
    return popped_elem;
}


int main(){
    struct Node * stack = NULL;
    printf("Stack\n");
    display(stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("After pushing element in stack: \n");
    display(stack);
    pop(&stack);
    printf("After popping element in stack: \n");
    display(stack);
    return 0;
}