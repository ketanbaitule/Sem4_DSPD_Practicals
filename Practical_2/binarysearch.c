#include <stdio.h>

int binarySearch(int * arr, int n, int key){
    int low = 0;
    int high = n-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key){
            return mid;
        }else if (key > arr[mid])
        {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;    
}

int main(){
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;

    int idx = binarySearch(arr, n, key);

    printf("Index of %d in arr is %d", key, idx);
    return 0;
}