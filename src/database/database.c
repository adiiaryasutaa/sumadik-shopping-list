//
// Created by adiaryasuta on 26/06/2024.
//

#include "database/database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entity/item.h"

const char* item_json_file_path = "C:/Users/adiar/Dev/sumadik-shopping-list/src/database/data/item.json";
const char* category_json_file_path = "C:/Users/adiar/Dev/sumadik-shopping-list/src/database/data/category.json";

const char* get_item_json_file_path()
{
    return item_json_file_path;
}

const char* get_category_json_file_path()
{
    return category_json_file_path;
}

char* read_file(const char* path)
{
    FILE* file = fopen(path, "r");
    // printf("Opening file [%s]\n", path);

    if (file == NULL)
    {
        printf("Error opening file [%s]\n", path);

        exit(EXIT_FAILURE);
    }

    // printf("File opened [%s]\n", path);

    fseek(file, 0, SEEK_END);
    const long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = malloc(length + 1);
    if (content == NULL)
    {
        perror("Failed to allocate memory");
        fclose(file);

        exit(EXIT_FAILURE);
    }

    fread(content, 1, length, file);
    content[length] = '\0';

    fclose(file);

    const size_t buffer_len = strlen(content);
    const size_t total_len = buffer_len + 2;

    char* result = malloc(total_len);
    if (result == NULL)
    {
        perror("Failed to allocate memory [func:get_database_item_full_path]");
        exit(EXIT_FAILURE);
    }

    snprintf(result, total_len, "%s\n", content);

    return result;
}

char* read_item_file()
{
    return read_file(item_json_file_path);
}

char* read_category_file()
{
    return read_file(category_json_file_path);
}

cJSON* read_category_json()
{
    return cJSON_Parse(read_category_file());
}

cJSON* read_item_json()
{
    return cJSON_Parse(read_item_file());
}

int write(const char* path, const char* data)
{
    FILE* file = fopen(path, "w");
    if (file == NULL)
    {
        perror("Failed to open file for writing");

        exit(EXIT_FAILURE);
    }

    const int result = fprintf(file, "%s\n", data);
    fclose(file);

    return result;
}

int write_item(const char* data)
{
    return write(get_item_json_file_path(), data);
}

int write_category(const char* data)
{
    return write(get_category_json_file_path(), data);
}

cJSON* create_category_json(const Category category)
{
    cJSON* new_json_category = cJSON_CreateObject();
    cJSON_AddNumberToObject(new_json_category, "id", category.id);
    cJSON_AddStringToObject(new_json_category, "name", category.name);

    return new_json_category;
}

cJSON* get_category_data_json()
{
    const cJSON* json_categories = read_category_json();
    cJSON* data = cJSON_GetObjectItemCaseSensitive(json_categories, "data");
    if (!cJSON_IsArray(data))
    {
        printf("data is not array [category]\n");

        exit(EXIT_FAILURE);
    }

    return data;
}

int get_category_size()
{
    const cJSON* data = get_category_data_json();
    return cJSON_GetArraySize(data);
}

int get_category_last_id()
{
    const cJSON* data = get_category_data_json();
    const int size = get_category_size();

    if (size <= 0)
    {
        return 1;
    }

    const cJSON* last_category = cJSON_GetArrayItem(data, size - 1);
    const cJSON* last_category_id = cJSON_GetObjectItem(last_category, "id");

    return cJSON_GetNumberValue(last_category_id) + 1;
}

int insert_category(const Category category)
{
    cJSON* category_json = create_category_json(category);

    const cJSON* json_categories = read_category_json();
    cJSON* data = cJSON_GetObjectItemCaseSensitive(json_categories, "data");
    if (!cJSON_IsArray(data))
    {
        printf("data is not array [category]\n");

        exit(EXIT_FAILURE);
    }

    cJSON_AddItemToArray(data, category_json);

    return write_category(cJSON_Print(json_categories));
}

int get_all_categories(Category* categories)
{
    const cJSON* data = get_category_data_json();
    const int size = cJSON_GetArraySize(data);

    for (int i = 0; i < size; i++)
    {
        const cJSON* category_json = cJSON_GetArrayItem(data, i);
        const cJSON* id = cJSON_GetObjectItem(category_json, "id");
        const cJSON* name = cJSON_GetObjectItem(category_json, "name");

        const Category category = {
            cJSON_GetNumberValue(id),
            cJSON_GetStringValue(name),
        };

        categories[i] = category;
    }

    return size;
}

Category* find_category(const char* name)
{
    const int size = get_category_size();
    Category categories[size];
    get_all_categories(categories);

    for (int i = 0; i < size; i++)
    {
        if (!strcmp(categories[i].name, name))
        {
            Category* category = &categories[i];
            return category;
        }
    }

    return NULL;
}

bool destroy_category(const Category* category)
{
    const cJSON* json_categories = read_category_json();
    cJSON* data = cJSON_GetObjectItemCaseSensitive(json_categories, "data");

    // search
    const int size = cJSON_GetArraySize(data);
    for (int i = 0; i < size; i++)
    {
        const cJSON* category_json = cJSON_GetArrayItem(data, i);
        const cJSON* id = cJSON_GetObjectItem(category_json, "id");

        if (cJSON_GetNumberValue(id) == category->id)
        {
            cJSON_DeleteItemFromArray(data, i);
            write_category(cJSON_Print(json_categories));

            return true;
        }
    }

    return false;
}

cJSON* create_item_json(const Item item)
{
    cJSON* new_json_item = cJSON_CreateObject();
    cJSON_AddNumberToObject(new_json_item, "id", item.id);
    cJSON_AddStringToObject(new_json_item, "name", item.name);
    cJSON_AddNumberToObject(new_json_item, "quantity", item.quantity);
    cJSON_AddNumberToObject(new_json_item, "category_id", item.category_id);

    return new_json_item;
}

cJSON* get_item_data_json()
{
    const cJSON* json_items = read_item_json();
    cJSON* data = cJSON_GetObjectItemCaseSensitive(json_items, "data");
    if (!cJSON_IsArray(data))
    {
        printf("data is not array [item]\n");
        exit(EXIT_FAILURE);
    }

    return data;
}

int get_item_size()
{
    const cJSON* data = get_item_data_json();
    return cJSON_GetArraySize(data);
}

int get_item_last_id()
{
    const cJSON* data = get_item_data_json();
    const int size = get_item_size();

    if (size <= 0)
    {
        return 1;
    }

    const cJSON* last_item = cJSON_GetArrayItem(data, size - 1);
    const cJSON* last_item_id = cJSON_GetObjectItem(last_item, "id");

    return cJSON_GetNumberValue(last_item_id) + 1;
}

int insert_item(const Item item)
{
    cJSON* item_json = create_item_json(item);

    const cJSON* json_items = read_item_json();
    cJSON* data = cJSON_GetObjectItemCaseSensitive(json_items, "data");
    if (!cJSON_IsArray(data))
    {
        printf("data is not array [item]\n");
        exit(EXIT_FAILURE);
    }

    cJSON_AddItemToArray(data, item_json);

    return write_item(cJSON_Print(json_items));
}

int get_all_items(Item* items)
{
    const cJSON* data = get_item_data_json();
    const int size = cJSON_GetArraySize(data);

    for (int i = 0; i < size; i++)
    {
        const cJSON* item_json = cJSON_GetArrayItem(data, i);
        const cJSON* id = cJSON_GetObjectItem(item_json, "id");
        const cJSON* name = cJSON_GetObjectItem(item_json, "name");
        const cJSON* quantity = cJSON_GetObjectItem(item_json, "quantity");
        const cJSON* category_id = cJSON_GetObjectItem(item_json, "category_id");

        const Item item = {
            cJSON_GetNumberValue(id),
            cJSON_GetStringValue(name),
            cJSON_GetNumberValue(quantity),
            cJSON_GetNumberValue(category_id)
        };

        items[i] = item;
    }

    return size;
}

Item* find_item(const char* name)
{
    const int size = get_item_size();
    Item items[size];
    get_all_items(items);

    for (int i = 0; i < size; i++)
    {
        if (!strcmp(items[i].name, name))
        {
            Item* item = &items[i];
            return item;
        }
    }

    return NULL;
}

bool destroy_item(const Item* item)
{
    const cJSON* json_items = read_item_json();
    cJSON* data = cJSON_GetObjectItemCaseSensitive(json_items, "data");

    // Search
    const int size = cJSON_GetArraySize(data);
    for (int i = 0; i < size; i++)
    {
        const cJSON* item_json = cJSON_GetArrayItem(data, i);
        const cJSON* name = cJSON_GetObjectItem(item_json, "name");

        if (!strcmp(cJSON_GetStringValue(name), item->name))
        {
            cJSON_DeleteItemFromArray(data, i);
            write_item(cJSON_Print(json_items));
            return true;
        }
    }

    return false;
}
