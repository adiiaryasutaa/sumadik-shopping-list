//
// Created by adiaryasuta on 26/06/2024.
//

#include "service/menu_service.h"

#include <stdio.h>
#include <stdlib.h>

int menu()
{
    system("clear");
    int choice;

    printf("\nSUMADIK SHOPPING LIST\n");
    printf("Menu:\n");
    printf("1. Tambah Kategori\n");
    printf("2. Cari Kategori\n");
    printf("3. Hapus Kategori\n");
    printf("4. Tambah Belanjaan\n");
    printf("5. Cari Belanjaan\n");
    printf("6. Hapus Belanjaan\n");
    printf("7. Hitung Total Belanjaan\n");
    printf("8. Keluar\n");
    printf("Pilih Menu [1-8]: ");

    scanf("%d", &choice);

    return choice;
}
