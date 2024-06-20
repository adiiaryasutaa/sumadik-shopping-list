//
// Created by adiaryasuta on 20/06/2024.
//

#ifndef CATEGORY_SERVICE_H
#define CATEGORY_SERVICE_H

#include "entity/category.h"

void addCategory(Category* categories, int* categoryCount);

void searchCategory(Category* categories, int categoryCount, char* name);

void deleteCategory(Category* categories, int* categoryCount, char* name);

#endif //CATEGORY_SERVICE_H
