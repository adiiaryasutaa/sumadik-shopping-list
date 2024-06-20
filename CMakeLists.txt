cmake_minimum_required(VERSION 3.28)
project(sumadik_shopping_list C)

include_directories(include)

set(CMAKE_C_STANDARD 23)

add_executable(
        sumadik_shopping_list src/main.c
        include/entity/item.h
        include/entity/category.h
        src/service/item_service.c
        include/service/item_service.h
        src/service/category_service.c
        include/service/category_service.h
)
