#include <stdio.h>
#include <stdlib.h>
#include <assert.h>  
#include <stdbool.h>


void findTwoSum(int arr[], int size, int target, int *index1, int *index2) {
    

    int left = 0, right = size - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            *index1 = left;
            *index2 = right;
            return;
        } else if (sum < target) {
            left++; 
        } else {
            right--; 
        }
    }
    *index1 = -1;
    *index2 = -1;
}
void printArray(int arr[], int size) {
    printf("arr = { ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");  // Добавляем запятую, кроме последнего элемента
        }
    }
    printf(" }\n");
}
// Функция тестирования
void test_findTwoSum() {
    int index1, index2;

    // Тест 1: Обычный случай
    int arr1[] = {1, 2, 3, 4, 6, 8, 10};
    findTwoSum(arr1, 7, 10, &index1, &index2);
    printArray(arr1, sizeof(arr1)/sizeof(int));
    printf("Target = 10\n");
    printf("First index = %d, Second index = %d \n", index1, index2 );
    assert((index1 == 1 && index2 == 5) || (index1 == 3 && index2 == 4));
    printf("\033[1;31mTest 1 passed\033[0m\n");

    // Тест 2: Нет решения
    int arr2[] = {1, 3, 5, 7};
    findTwoSum(arr2, 4, 20, &index1, &index2);
    printArray(arr2, sizeof(arr2)/sizeof(int));
    printf("Target = 20\n");
    printf("First index = %d, Second index = %d \n", index1, index2 );
    assert(index1 == -1 && index2 == -1);
    printf("\033[1;31mTest 2 passed\033[0m\n");

    // Тест 3: Только одно возможное решение
    int arr3[] = {2, 7, 11, 15};
    findTwoSum(arr3, 4, 9, &index1, &index2);
    printArray(arr3, sizeof(arr3)/sizeof(int));
    printf("Target = 9\n");
    printf("First index = %d, Second index = %d \n", index1, index2 );
    assert(index1 == 0 && index2 == 1);
    printf("\033[1;31mTest 3 passed\033[0m\n");

    // Тест 4: Массив с отрицательными числами
    int arr4[] = {-3, 1, 4, 6, 9};
    findTwoSum(arr4, 5, 5, &index1, &index2);
    printArray(arr4, sizeof(arr4)/sizeof(int));
    printf("Target = 5\n");
    printf("First index = %d, Second index = %d \n", index1, index2 );
    assert(index1 == 1 && index2 == 2);
    printf("\033[1;31mTest 4 passed\033[0m\n");

}

int main() {
    test_findTwoSum();
    printf("All tests passed!\n");
    return 0;
}
