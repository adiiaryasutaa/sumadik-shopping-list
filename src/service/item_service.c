//
// Created by adiaryasuta on 20/06/2024.
//

#include "service/item_service.h"
#include "entity/item.h"

#include <stdio.h>
#include <string.h>

#include "database/database.h"

void add_item()
{
    printf("TAMBAH BELANJAAN\n");
    printf("Daftar Kategori Tersedia:\n");
    const int size = get_category_size();
    Category categories[size];
    get_all_categories(categories);

    for (int i = 0; i < size; i++)
    {
        printf("%d. %s\n", i + 1, categories[i].name);
    }
    printf("Tekan 0 untuk menghentikan penambahan.\n\n");

    while (true)
    {
        int selected_category;
        printf("Kategori Barang ke - 1 [1-%d]: ", size);
        scanf("%d", &selected_category);

        if (selected_category <= 0)
        {
            break;
        }

        char name[100];
        printf("Nama Barang ke - 1: ");
        scanf("%s", name);

        int quantity;
        printf("Masukan jumlah barang ke - 1: ");
        scanf("%d", &quantity);

        const Item item = {
            get_item_last_id(),
            name,
            quantity,
            categories[selected_category - 1].id
        };

        insert_item(item);

        printf("Barang Belanjaan Ditambahkan!\n\n");
    }
}

void search_item()
{
    printf("CARI BELANJAAN\n");
    printf("Tekan underscore untuk menghentikan pencarian.\n\n");

    while (true)
    {
        char name[100];
        printf("Masukan nama barang: ");
        scanf("%s", name);

        if (!strcmp(name, "_"))
        {
            break;
        }

        const Item* item = find_item(name);

        if (item == NULL)
        {
            printf("Belanjaan tidak ditemukan!\n\n");
        }
        else
        {
            printf("Belanjaan ditemukan!\n\n");
        }
    }
}

void delete_item()
{
    printf("HAPUS BARANG\n");
    printf("Tekan 0 untuk menghentikan penghapusan.\n\n");

    while (true)
    {
        const int size = get_item_size();
        Item items[size];
        get_all_items(items);

        for (int i = 0; i < size; i++)
        {
            printf("%d. %s\n", i + 1, items[i].name);
        }

        printf("Pilih Barang yang akan dihapus [1-%d]: ", size);

        int selection;
        scanf("%d", &selection);

        if (selection <= 0)
        {
            break;
        }

        const Item* selected_item = &items[selection - 1];

        destroy_item(selected_item);

        printf("Barang Dihapus!\n\n");
    }
}

void calculate_total_price()
{
    printf("HITUNG TOTAL BELANJA\n");
    printf("Berikut adalah daftar belanjaan:\n\n");

    const int size = get_item_size();
    Item items[size];
    get_all_items(items);

    int total = 0;

    for (int i = 0; i < size; i++)
    {
        printf("%d. %s - %d buah\n", i + 1, items[i].name, items[i].quantity);
        printf("Masukan harga beli: ");
        int price;
        scanf("%d", &price);

        total += price * items[i].quantity;
        printf("Sub total harga belanjaan adalah Rp %d\n\n", total);
    }

    printf("Total harga belanjaan adalah Rp %d\n\n", total);
}
