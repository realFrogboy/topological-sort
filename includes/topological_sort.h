#pragma once

#include "list.h"

struct elem_t {
    int count;
    list_t* lst;
};

struct elem_arr_t {
    elem_t* arr;
    size_t size;
};

elem_arr_t* get_data();
void elem_arr_dtor(elem_arr_t* elem_arr);
list_t* queue_ctor(elem_arr_t* elem_arr);
int sort(elem_arr_t* elem_arr);