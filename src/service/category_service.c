//
// Created by adiaryasuta on 20/06/2024.
//

#include "service/category_service.h"
#include "database/database.h"

#include <stdio.h>
#include <string.h>

Category categories[100];
int categoryCount = 0;

void add_category()
{
    printf("TAMBAH KATEGORI\n");
    printf("Tekan underscore untuk menghentikan penambahan.\n\n");

    while (true)
    {
        char name[100];
        printf("Nama Kategori: ");
        scanf("%s", name);

        if (!strcmp(name, "_"))
        {
            break;
        }

        Category category;

        category.id = get_category_last_id();
        category.name = name;

        insert_category(category);

        printf("Kategori Ditambahkan!\n\n");
    }
}

void search_category()
{
    printf("CARI KATEGORI\n");
    printf("Tekan underscore untuk menghentikan pencarian.\n\n");

    while (true)
    {
        char name[100];
        printf("Masukan nama kategori: ");
        scanf("%s", name);

        if (!strcmp(name, "_"))
        {
            break;
        }

        const Category* category = find_category(name);

        if (category == NULL)
        {
            printf("Kategori tidak ditemukan!\n\n");
        }
        else
        {
            printf("Kategori ditemukan!\n\n");
        }
    }
}

void delete_category()
{
    printf("HAPUS KATEGORI\n");
    printf("Tekan 0 untuk menghentikan penghapusan.\n\n");

    while (true)
    {
        const int size = get_category_size();
        const Category categories[size];
        get_all_categories(categories);

        for (int i = 0; i < size; i++)
        {
            printf("%d. %s\n", i + 1, categories[i].name);
        }

        printf("Pilih Kategori yang akan dihapus [1-%d]: ", size);

        int selection;
        scanf("%d", &selection);

        if (selection <= 0)
        {
            break;
        }

        const Category* selected_category = &categories[selection - 1];

        destroy_category(selected_category);

        printf("Kategori Dihapus!\n\n");
    }
}
