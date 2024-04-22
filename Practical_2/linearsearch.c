#include <stdio.h>

int linearSearch(int * arr, int n, int key){
    int idx = -1;

    for (int i=0; i < n; i++){
        if(arr[i] == key){
            idx = i;
            break;
        }
    }

    return idx;
}

int main(){
    int arr[] = { 10, 50, 30, 70, 80, 20, 90, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    int idx = linearSearch(arr, n, key);

    printf("Index of %d in arr is %d", key, idx);
    return 0;
}