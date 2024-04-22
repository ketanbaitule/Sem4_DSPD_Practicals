#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Stack type
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack
        = (struct Stack*)malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array
        = (int*)malloc(stack->capacity * sizeof(int));
 
    if (!stack->array)
        return NULL;
 
    return stack;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
 
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
 
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

int evaluatePostFixExp(char * exp){
    struct Stack * s = createStack(strlen(exp));
    printf("Test: %s\n", exp);

    for (int i=0; i<strlen(exp); i++){
        if (exp[i] == ' ')
            continue;
        if(isdigit(exp[i]) != 0){
            int n = exp[i++] - '0';
            while(isdigit(exp[i]) != 0){
                n = n * 10 + (exp[i] - '0');
                i++;
            }
            printf("Num: %d\n", n);
            push(s, (int)n);
            continue;
        }

        char val1 = pop(s);
        char val2 = pop(s); 
    
        switch(exp[i]){
            case '+':
                push(s, val2 + val1);
                printf("Add: %d + %d = %d\n", val2, val1, (val2 + val1));
                break;
            case '-':
                push(s, val2 - val1);
                break;
            case '*':
                push(s, val2 * val1);
                break;
            case '/':
                push(s, val2 / val1);
                break;
            case '%':
                push(s, val2 % val1);
                break;
        }
    }
    return pop(s);
}

int main(){
    char exp[] = "100 200 +";
    printf("Postfix Evaluation: %d\n", evaluatePostFixExp(exp));
    return 0;
}