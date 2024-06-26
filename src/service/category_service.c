//
// Created by adiaryasuta on 20/06/2024.
//

#include "service/category_service.h"

#include <stdio.h>
#include <string.h>

Category categories[100];
int categoryCount = 0;

void add_category()
{
    printf("Enter category name: ");
    scanf("%s", categories[categoryCount].name);
    categoryCount++;
}

void search_category(const char* name)
{
    int found = 0;
    for (int i = 0; i < categoryCount; i++)
    {
        if (strcmp(categories[i].name, name) == 0)
        {
            printf("Category: %s\n", categories[i].name);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Category not found.\n");
    }
}

void delete_category(const char* name)
{
    for (int i = 0; i < categoryCount; i++)
    {
        if (strcmp(categories[i].name, name) == 0)
        {
            for (int j = i; j < categoryCount - 1; j++)
            {
                categories[j] = categories[j + 1];
            }
            categoryCount--;
            printf("Category deleted successfully.\n");
            return;
        }
    }
    printf("Category not found.\n");
}
