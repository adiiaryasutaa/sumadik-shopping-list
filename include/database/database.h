//
// Created by adiaryasuta on 26/06/2024.
//

#ifndef DATABASE_H
#define DATABASE_H

#include "cJSON.h"
#include "entity/category.h"
#include "entity/item.h"

const char* get_item_json_file_path();

const char* get_category_json_file_path();

char* read_file(const char* path);

char* read_item_file();

char* read_category_file();

cJSON* read_category_json();

cJSON* read_item_json();

int write(const char *path, const char *data);

int write_item(const char *data);

int write_category(const char *data);

cJSON* create_category_json(Category category);

cJSON* get_category_data_json();

int get_category_size();

int get_category_last_id();

int insert_category(Category category);

int get_all_categories(Category *categories);

Category* find_category(const char* name);

bool destroy_category(const Category *category);

cJSON* create_item_json(const Item item);

cJSON* get_item_data_json();

int get_item_size();

int get_item_last_id();

int insert_item(const Item item);

int get_all_items(Item* items);

Item* find_item(const char* name);

bool destroy_item(const Item* item);

#endif //DATABASE_H
