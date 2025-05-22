#include <stdio.h>
#include <stdlib.h>

void rearrange(int *ptr, int size) {
    int *temp = malloc(size * sizeof(int));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    int *head = temp; // Save head pointer
    printf("\n\tHead pointer is %p\n", head);
     // Copy even numbers
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 == 0) {
            *temp = *(ptr + i);  // Copy value
            temp++;
        }
    }
    //  Copy odd numbers
    for (int i = 0; i < size; i++) {
        if (*(ptr + i) % 2 != 0) {
            *temp = *(ptr + i);
            temp++;
        }
    }
    //  Print original array and copy the rearranged array onto original array
    printf("\nOriginal array:\n");
    for (int *p = ptr; p < ptr + size; p++) {
        printf("%d ", *p);
        *p=*(head);
        head++;
    }
    free(head);  // Free dynamically allocated memory
}

int main() {
    int n;
    printf("Enter the Number of Elements: ");
    scanf("%d", &n);
    int arr[n];
    int *t=arr;
    for (int i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", t+i);
    }
    rearrange(arr, n);
    // Print rearranged array
    printf("\nRearranged array:\n");
    for (int *p = arr; p < arr + n; p++) {
        printf("%d ", *p);
    }
    return 0;
}
