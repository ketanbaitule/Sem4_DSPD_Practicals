#include <stdio.h>

void print_array(int * arr, int n){
    for (int i=0; i < n; i++){
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int * arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j< n - i -1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = { 6, 3, 0, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    print_array(arr, n);

    bubble_sort(arr, n);

    print_array(arr, n);

    return 0;
}