//
// Created by adiaryasuta on 20/06/2024.
//

#include "service/item_service.h"
#include "entity/item.h"

#include <stdio.h>
#include <string.h>

Item shoppingList[100];
int itemCount = 0;

void add_item()
{
    printf("Enter item name: ");
    scanf("%s", shoppingList[itemCount].name);
    printf("Enter item quantity: ");
    scanf("%d", &shoppingList[itemCount].quantity);
    printf("Enter item price: ");
    scanf("%f", &shoppingList[itemCount].price);
    printf("Enter item category: ");
    scanf("%s", shoppingList[itemCount].category);

    itemCount++;
}

void search_item(const char* name)
{
    int found = 0;

    for (int i = 0; i < itemCount; i++)
    {
        if (strcmp(shoppingList[i].name, name) == 0)
        {
            printf("Name: %s\n", shoppingList[i].name);
            printf("Quantity: %d\n", shoppingList[i].quantity);
            printf("Price: %.2f\n", shoppingList[i].price);
            printf("Category: %s\n", shoppingList[i].category);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Item not found.\n");
    }
}

void delete_item(const char* name)
{
    for (int i = 0; i < itemCount; i++)
    {
        if (strcmp(shoppingList[i].name, name) == 0)
        {
            for (int j = i; j < itemCount - 1; j++)
            {
                shoppingList[j] = shoppingList[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

float calculate_total_price()
{
    float total = 0;

    for (int i = 0; i < itemCount; i++)
    {
        total += shoppingList[i].price * shoppingList[i].quantity;
    }

    return total;
}
