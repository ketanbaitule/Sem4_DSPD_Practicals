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

void insertion_sort(int * arr, int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int sorted_array_idx = i - 1;
        while (sorted_array_idx >= 0 && arr[sorted_array_idx] > key)
        {
            arr[sorted_array_idx + 1] = arr[sorted_array_idx];
            sorted_array_idx--;
        }
        arr[sorted_array_idx + 1] = key;        
    }
}

int main(){
    int arr[] = { 6, 3, 0, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    print_array(arr, n);

    insertion_sort(arr, n);

    print_array(arr, n);

    return 0;
}