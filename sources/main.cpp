#include <stdio.h>
#include "topological_sort.h"

int main() {
    elem_arr_t* elem_arr = get_data();

    int remaining = sort(elem_arr);
    (remaining != 0) ? printf("\nCan't sort\n") : printf("\nSuccess\n");

    elem_arr_dtor(elem_arr);

    return 0;
}