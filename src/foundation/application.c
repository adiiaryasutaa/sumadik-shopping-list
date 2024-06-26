//
// Created by adiaryasuta on 26/06/2024.
//

#include "foundation/application.h"
#include "service/menu_service.h"

#include "service/item_service.h"
#include "service/category_service.h"

#include <stdio.h>

void run_app()
{
    int selection = 0;

    do
    {
        char name[50];
        selection = menu();

        switch (selection)
        {
        case 1:
            add_item();
            break;
        case 2:
            printf("Enter item name to search: ");
            scanf("%s", name);
            search_item(name);
            break;
        case 3:
            printf("Enter item name to delete: ");
            scanf("%s", name);
            delete_item(name);
            break;
        case 4:
            add_category();
            break;
        case 5:
            printf("Enter category name to search: ");
            scanf("%s", name);
            search_category(name);
            break;
        case 6:
            printf("Enter category name to delete: ");
            scanf("%s", name);
            delete_category(name);
            break;
        case 7:
            printf("Total shopping cost: %.2f\n", calculate_total_price());
            break;
        case 0:
            printf("Thank you!\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    while (selection != 0);
}
