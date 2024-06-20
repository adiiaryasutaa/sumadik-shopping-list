#include <stdio.h>

#include "entity/category.h"
#include "entity/item.h"
#include "service/item_service.h"
#include "service/category_service.h"

int main()
{
    Item shoppingList[100];
    Category categories[100];
    int itemCount = 0;
    int categoryCount = 0;
    int choice;
    char name[50];

    do
    {
        printf("\nMenu:\n");
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

        switch (choice)
        {
        case 1:
            addItem(shoppingList, &itemCount);
            break;
        case 2:
            printf("Enter item name to search: ");
            scanf("%s", name);
            searchItem(shoppingList, itemCount, name);
            break;
        case 3:
            printf("Enter item name to delete: ");
            scanf("%s", name);
            deleteItem(shoppingList, &itemCount, name);
            break;
        case 4:
            addCategory(categories, &categoryCount);
            break;
        case 5:
            printf("Enter category name to search: ");
            scanf("%s", name);
            searchCategory(categories, categoryCount, name);
            break;
        case 6:
            printf("Enter category name to delete: ");
            scanf("%s", name);
            deleteCategory(categories, &categoryCount, name);
            break;
        case 7:
            printf("Total shopping cost: %.2f\n", calculateTotalCost(shoppingList, itemCount));
            break;
        case 0:
            printf("Thank you!\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    while (choice != 0);

    return 0;
}
