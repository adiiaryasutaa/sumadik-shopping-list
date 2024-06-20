//
// Created by adiaryasuta on 20/06/2024.
//

#include "service/category_service.h"

#include <stdio.h>
#include <string.h>

void addCategory(Category* categories, int* categoryCount)
{
    printf("Enter category name: ");
    scanf("%s", categories[*categoryCount].name);
    (*categoryCount)++;
}

void searchCategory(Category* categories, int categoryCount, char* name)
{
    int i, found = 0;
    for (i = 0; i < categoryCount; i++)
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

void deleteCategory(Category* categories, int* categoryCount, char* name)
{
    int i, j;
    for (i = 0; i < *categoryCount; i++)
    {
        if (strcmp(categories[i].name, name) == 0)
        {
            for (j = i; j < *categoryCount - 1; j++)
            {
                categories[j] = categories[j + 1];
            }
            (*categoryCount)--;
            printf("Category deleted successfully.\n");
            return;
        }
    }
    printf("Category not found.\n");
}
