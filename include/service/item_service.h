//
// Created by adiaryasuta on 20/06/2024.
//

#ifndef ITEM_SERVICE_H
#define ITEM_SERVICE_H

#include "entity/item.h"

void addItem(Item* shoppingList, int* itemCount);

void searchItem(Item* shoppingList, int itemCount, char* name);

void deleteItem(Item* shoppingList, int* itemCount, char* name);

float calculateTotalCost(Item* shoppingList, int itemCount);

#endif //ITEM_SERVICE_H
