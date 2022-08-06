#include <stdio.h>
#include "topological_sort.h"

int main() {
    elem_arr_t* elem_arr = get_data();
    elem_arr_dtor(elem_arr);

    return 0;
}