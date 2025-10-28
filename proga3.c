#include <stdio.h>
#include <string.h>

int main() {
    FILE *f, *temp;
    char action[10];
    char name[100], phone[50], email[100], line[200];

    printf("Что сделать? (add / search / delete): ");
    scanf("%9s", action);

    if (strcmp(action, "add") == 0) {
        printf("Имя: ");
        scanf("%99s", name);
        printf("Телефон: ");
        scanf("%49s", phone);
        printf("Email: ");
        scanf("%99s", email);

        f = fopen("contacts.txt", "a");
        fprintf(f, "%s,%s,%s\n", name, phone, email);
        fclose(f);

        printf("Контакт добавлен.\n");
    }
      
    else if (strcmp(action, "search") == 0) {
        char query[100];
        printf("Введите строку для поиска: ");
        scanf("%99s", query);

        f = fopen("contacts.txt", "r");
        if (!f) {
            printf("Файл не найден.\n");
            return 0;
        }

        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, query))
                printf("%s", line);
        }

        fclose(f);
    }

    else if (strcmp(action, "delete") == 0) {
        char delname[100];
        printf("Введите имя для удаления: ");
        scanf("%99s", delname);

        f = fopen("contacts.txt", "r");
        temp = fopen("temp.txt", "w");
        if (!f || !temp) {
            printf("Ошибка открытия файла.\n");
            return 0;
        }

        while (fgets(line, sizeof(line), f)) {
            if (strncmp(line, delname, strlen(delname)) != 0)
                fputs(line, temp);
        }

        fclose(f);
        fclose(temp);
      
        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");

        printf("Контакт удалён (если был найден).\n");
    }

    else {
        printf("Неизвестное действие.\n");
    }

    return 0;
}
