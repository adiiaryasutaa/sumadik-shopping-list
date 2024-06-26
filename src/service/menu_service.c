//
// Created by adiaryasuta on 26/06/2024.
//

#include "service/menu_service.h"

#include <stdio.h>

int menu()
{
    int choice;

    printf("\nSUMADIK SHOPPING LIST\n");
    printf("Menu:\n");
    printf("1. Add item\n");
    printf("2. Search item\n");
    printf("3. Delete item\n");
    printf("4. Add category\n");
    printf("5. Search category\n");
    printf("6. Delete category\n");
    printf("7. Calculate total shopping cost\n");
    printf("0. Exit\n");
    printf("Enter choice: ");

    scanf("%d", &choice);

    return choice;
}