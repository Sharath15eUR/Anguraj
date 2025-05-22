#include <stdio.h>
#include <stdlib.h>

int searchMatrix(int **matrix, int n, int key) {
    int row = 0, col = n - 1;

    while (row < n && col >= 0) {
        int current = *(*(matrix + row) + col);

        if (current == key) {
            printf("Key %d found at (%d, %d)\n", key, row, col);
            return 1;
        } else if (current > key) {
            col--;
        } else {
            row++;
        }
    }

    printf("Key %d not found.\n", key);
    return 0;
}

int main() {
    int n, key;
    printf("Enter matrix size (n x n): ");
    scanf("%d", &n);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(matrix + i) = (int *)malloc(n * sizeof(int));
    }

    printf("Enter matrix elements (each row & column sorted):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", (*(matrix + i) + j));
        }
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    searchMatrix(matrix, n, key);

    for (int i = 0; i < n; i++) {
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}
