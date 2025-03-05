#include <stdio.h>

void findTwoSum(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            printf("Индексы: %d, %d\n", left, right);
            return;
        } else if (sum < target) {
            left++; 
        } else {
            right--; 
        }
    }
    printf("No two numbers found.\n");
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 6, 8, 10}; // Отсортированный массив
    int target = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    findTwoSum(arr, size, target);
    return 0;
}
