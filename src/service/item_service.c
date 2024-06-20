//
// Created by adiaryasuta on 20/06/2024.
//

#include "service/item_service.h"

#include <stdio.h>
#include <string.h>

void addItem(Item* shoppingList, int* itemCount)
{
    printf("Enter item name: ");
    scanf("%s", shoppingList[*itemCount].name);
    printf("Enter item quantity: ");
    scanf("%d", &shoppingList[*itemCount].quantity);
    printf("Enter item price: ");
    scanf("%f", &shoppingList[*itemCount].price);
    printf("Enter item category: ");
    scanf("%s", shoppingList[*itemCount].category);

    (*itemCount)++;
}

void searchItem(Item* shoppingList, int itemCount, char* name)
{
    int i, found = 0;
    for (i = 0; i < itemCount; i++)
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

void deleteItem(Item* shoppingList, int* itemCount, char* name)
{
    int i, j;
    for (i = 0; i < *itemCount; i++)
    {
        if (strcmp(shoppingList[i].name, name) == 0)
        {
            for (j = i; j < *itemCount - 1; j++)
            {
                shoppingList[j] = shoppingList[j + 1];
            }
            (*itemCount)--;
            printf("Item deleted successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

float calculateTotalCost(Item* shoppingList, int itemCount)
{
    float total = 0;
    int i;
    for (i = 0; i < itemCount; i++)
    {
        total += shoppingList[i].price * shoppingList[i].quantity;
    }
    return total;
}
