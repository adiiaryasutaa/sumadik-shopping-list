//
// Created by adiaryasuta on 26/06/2024.
//

#include "foundation/application.h"
#include "service/menu_service.h"

#include "service/item_service.h"
#include "service/category_service.h"

#include <stdio.h>
#include <stdlib.h>

void run_app()
{
    while (true)
    {
        const int selection = menu();

        switch (selection)
        {
        case 1:
            system("clear");
            add_category();
            break;
        case 2:
            system("clear");
            search_category();
            break;
        case 3:
            system("clear");
            delete_category();
            break;
        case 4:
            system("clear");
            add_item();
            break;
        case 5:
            system("clear");
            search_item();
            break;
        case 6:
            system("clear");
            delete_item();
            break;
        case 7:
            system("clear");
            calculate_total_price();
            return;
        case 8:
            system("clear");
            printf("Terima Kasih!\n");
            return;
        default:
            printf("Pilihan Tidak Valid.\n");
            break;
        }
    }
}
