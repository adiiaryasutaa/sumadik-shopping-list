//
// Created by adiaryasuta on 26/06/2024.
//

#include "database/database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

const char* database_path = "C:/Users/adiar/Dev/sumadik-shopping-list/src/database/data";
const char* item_json_file_name = "item.json";
const char* category_json_file_name = "category.json";

char* get_database_item_full_path()
{
    const size_t len1 = strlen(database_path);
    const size_t len2 = strlen(item_json_file_name);
    const size_t total_len = len1 + len2 + 2;

    char* result = malloc(total_len);
    if (result == NULL)
    {
        perror("Failed to allocate memory [func:get_database_item_full_path]");
        exit(EXIT_FAILURE);
    }

    snprintf(result, total_len, "%s/%s", database_path, item_json_file_name);

    return result;
}

void read_item()
{
    char* buffer = NULL;
    size_t buffer_size = 0;
    char temp[256];

    char* path = get_database_item_full_path();

    FILE* file = fopen(path, "r");
    printf("Opening file [%s]\n", path);

    if (file == NULL)
    {
        printf("Error opening file [%s]\n", path);
        free(path);

        return;
    }

    printf("File opened [%s]\n", path);

    while (fgets(temp, sizeof(temp), file) != NULL)
    {
        const size_t read_length = strlen(temp);

        // Reallocate buffer to accommodate new content
        char* new_buffer = realloc(buffer, buffer_size + read_length + 1);

        if (new_buffer == NULL)
        {
            free(buffer);

            perror("Error reallocating memory");
            break;
        }

        buffer = new_buffer;
        strcpy(buffer + buffer_size, temp);
        buffer_size += read_length;
    }

    fclose(file);

    if (buffer != NULL)
    {
        printf("File Content:\n%s", buffer);
        free(buffer);
    }
}

void write_item()
{
    // Create a JSON object
    cJSON *root = cJSON_CreateObject();

    // Add items to the JSON object
    cJSON_AddStringToObject(root, "name", "John Doe");
    cJSON_AddNumberToObject(root, "age", 30);
    cJSON_AddStringToObject(root, "city", "New York");

    // Create a nested JSON object
    cJSON *address = cJSON_CreateObject();
    cJSON_AddStringToObject(address, "street", "123 Main St");
    cJSON_AddStringToObject(address, "zipcode", "10001");
    cJSON_AddItemToObject(root, "address", address);

    // Print the JSON object as a string
    char *json_string = cJSON_Print(root);
    printf("%s\n", json_string);

    // Clean up
    cJSON_Delete(root);
    free(json_string);
}