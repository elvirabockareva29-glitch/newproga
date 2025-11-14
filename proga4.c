#include <stdio.h>

int main() {
    int n = 4, m = 4; 
    int a[100][100];
    printf("Введите элементы матрицы 4x4:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    int sum_neg = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i + j > n - 1 && a[i][j] < 0)  
                sum_neg += a[i][j];
    int min_pos = 1000000, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (a[i][1] > 0 && a[i][1] < min_pos) {
            min_pos = a[i][1];
            min_index = i;
        }
    }

    if (min_index != -1) {
        int temp = a[min_index][1];
        a[min_index][1] = a[1][3];
        a[1][3] = temp;
    }
    printf("\nСумма отрицательных элементов под побочной диагональю: %d\n", sum_neg);
    if (min_index != -1)
        printf("Минимальный положительный в 2 столбце: %d\n", min_pos);
    else
        printf("Положительных элементов во 2 столбце нет\n");
    printf("\nМатрица после обмена:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    return 0;
}

