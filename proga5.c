#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//пузырьковая сортировка
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

//сортировка вставками 
void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//сортировка слиянием
void merge(int *arr, int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int *temp = (int*)malloc((r - l + 1) * sizeof(int));

    while (i <= m && j <= r)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (i = 0; i < k; i++) arr[l + i] = temp[i];
    free(temp);
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//заполнение массива случайными значениями
void fillRandom(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

//ф-я измерения времени 
double testSorting(void (*sortFunc)(int*, int), int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    fillRandom(arr, n);

    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();

    free(arr);
    return (double)(end - start) / CLOCKS_PER_SEC;
}

double testMergeSorting(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    fillRandom(arr, n);

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    free(arr);
    return (double)(end - start) / CLOCKS_PER_SEC;
}
int main() {
    srand(time(NULL));

    int sizes[] = {10, 1000, 10000, 100000};
    int count = 4;

    printf("\nРазмер массива | Пузырек (сек) | Вставки (сек) | Слияние (сек)\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        int n = sizes[i];
        double t1 = testSorting(bubbleSort, n);
        double t2 = testSorting(insertionSort, n);
        double t3 = testMergeSorting(n);

        printf("%13d | %13f | %13f | %13f\n", n, t1, t2, t3);
    }

    return 0;
}
