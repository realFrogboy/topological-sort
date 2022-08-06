#include "topological_sort.h"

elem_arr_t* get_data() {

    unsigned n = 0;
    int tmp = scanf("%u", &n);
    assert(tmp == 1);

    elem_arr_t* elem_arr = (elem_arr_t*) calloc (1, sizeof(elem_arr_t));
    elem_arr->arr = (elem_t*) calloc (n, sizeof(elem_t));
    elem_arr->arr--;    // array begins from 1
    elem_arr->size = n;

    for (unsigned idx = 1; idx <= n; idx++)
        elem_arr->arr[idx].lst = list_ctor();

    int prev = 0, next = 0;
    tmp = scanf("%d %d", &prev, &next);
    assert(tmp == 2);

    while ((prev > 0) && (next > 0)) {
        elem_arr->arr[next].count++;
        ins_at_the_beg(elem_arr->arr[prev].lst, next);

        tmp = scanf("%d %d", &prev, &next);
        assert(tmp == 2);
    }

    return elem_arr;
}


void elem_arr_dtor(elem_arr_t* elem_arr) {
    assert(elem_arr);

    for (unsigned idx = 1; idx <= elem_arr->size; idx++)
        list_dtor(elem_arr->arr[idx].lst);

    free(++elem_arr->arr);
    free(elem_arr);
}