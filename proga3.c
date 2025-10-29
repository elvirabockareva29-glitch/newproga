#!/bin/bash

FILE="contacts.txt"

echo "Что сделать? (add / search / delete): "
read action

if [[ "$action" == "add" ]]; then
    echo "Имя: "
    read name
    echo "Телефон: "
    read phone
    echo "Email: "
    read email
    echo "$name,$phone,$email" >> "$FILE"
    echo "Контакт добавлен."

elif [[ "$action" == "search" ]]; then
    echo "Введите строку для поиска: "
    read query
    if [[ -f "$FILE" ]]; then
        grep -i "$query" "$FILE" || echo "Совпадений не найдено."
    else
        echo "Файл контактов не найден."
    fi

elif [[ "$action" == "delete" ]]; then
    echo "Введите имя для удаления: "
    read delname
    if [[ -f "$FILE" ]]; then
        grep -iv "^$delname," "$FILE" > temp.txt && mv temp.txt "$FILE"
        echo "Контакт удалён (если существовал)."
    else
        echo "Файл контактов не найден."
    fi

else
    echo "Неизвестное действие."
fi
