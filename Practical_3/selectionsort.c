#include <stdio.h>

void print_array(int * arr, int n){
    for (int i=0; i < n; i++){
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void swap(int * arr, int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void selection_sort(int * arr, int n){
    for(int i=0; i<n; i++){
        int smallest_idx = i;
        for(int j=i+1; j < n; j++){
            if(arr[smallest_idx] > arr[j]){
                smallest_idx = j;
            }
        } 
        swap(arr, i, smallest_idx);
    }
}

int main(){
    int arr[] = { 6, 3, 0, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    print_array(arr, n);

    selection_sort(arr, n);

    print_array(arr, n);

    return 0;
}