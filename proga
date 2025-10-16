#include <stdio.h>
#include <stdlib.h> //для работы с динам.памятью

int main() {
    int N;
    printf("Введите N: ");
    scanf("%d", &N);

    int *numbers = malloc(N * sizeof(int));
    if (numbers == NULL) {
        printf("Ошибка\n");
        return 1;
    }

    int length = 0;

    int rec(int sum) {  // рекурсивная функция внутри main
        if (sum == N) {
            for (int i = 0; i < length; i++) {
                if (i > 0) printf(" + ");
                printf("%d", numbers[i]);
            }
            printf("\n");
            return 0;
        }

        for (int i = 1; i <= N; i++) {
            int prime = 1;
            if (i > 1) {
                for (int j = 2; j * j <= i; j++) {
                    if (i % j == 0) {
                        prime = 0;
                        break;
                    }
                }
            }

            if (prime && sum + i <= N) {
                numbers[length++] = i;   
                rec(sum + i);            
                length--;               
            }
        }
        return 0;
    }

    printf("N = %d\n", N);
    rec(0); 

    free(numbers);// освобождение памяти
    return 0;
}
