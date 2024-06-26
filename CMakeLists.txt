cmake_minimum_required(VERSION 3.28)
project(sumadik_shopping_list C)

set(CMAKE_C_STANDARD 23)

include_directories(
        include
        lib/include
)

add_executable(
        sumadik_shopping_list
        include/entity/item.h
        include/entity/category.h
        src/service/item_service.c
        include/service/item_service.h
        src/service/category_service.c
        include/service/category_service.h
        include/database/database.h
        src/database/database.c
        src/main.c
        src/service/menu_service.c
        include/service/menu_service.h
        src/foundation/application.c
        include/foundation/application.h
        lib/include/cJSON.h
        lib/src/cJSON.c
)
