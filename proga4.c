#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("matrix.txt", "r");
    if (!f) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    int n, m;
    fscanf(f, "%d %d", &n, &m);  

    int **a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%d", &a[i][j]);

    fclose(f);

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
    printf("Сумма отрицательных элементов под побочной диагональю: %d\n", sum_neg);
    printf("Минимальный положительный элемент 2 столбца: %d\n", min_pos);

    printf("\nМатрица после обмена:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}
