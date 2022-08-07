#include "topological_sort.h"

elem_arr_t* get_data() {
    unsigned n = 0;
    int tmp = scanf("%u", &n);
    assert(tmp == 1);

    elem_arr_t* elem_arr = (elem_arr_t*) calloc (1, sizeof(elem_arr_t));
    elem_arr->arr = (elem_t*) calloc (n, sizeof(elem_t));
    elem_arr->size = n;

    for (unsigned idx = 0; idx < n; idx++)
        elem_arr->arr[idx].lst = list_ctor();

    int prev = 0, next = 0;
    tmp = scanf("%d %d", &prev, &next);
    assert(tmp == 2);

    while ((prev >= 0) && (next >= 0)) {
        elem_arr->arr[next].count++;
        ins_at_the_end(elem_arr->arr[prev].lst, next);

        tmp = scanf("%d %d", &prev, &next);
        assert(tmp == 2);
    }

    return elem_arr;
}

list_t* queue_ctor(elem_arr_t* elem_arr) {
    assert(elem_arr);
    
    list_t* q = list_ctor();

    for (int idx = 0; idx < elem_arr->size; idx++) {
        if (elem_arr->arr[idx].count == 0)
            ins_at_the_end(q, idx);
    }

    return q;
}


void elem_arr_dtor(elem_arr_t* elem_arr) {
    assert(elem_arr);

    for (unsigned idx = 0; idx < elem_arr->size; idx++)
        list_dtor(elem_arr->arr[idx].lst);

    free(elem_arr->arr);
    free(elem_arr);
}


int sort(elem_arr_t* elem_arr) {
    assert(elem_arr);

    int rem = elem_arr->size;
    list_t* output_q = queue_ctor(elem_arr);

    while (output_q->size != 0) {
        int elem = (int)output_q->arr[output_q->head].data;
        printf("%d ", elem);
        rem--;

        arr_t* ptr_elem = &elem_arr->arr[elem].lst->arr[elem_arr->arr[elem].lst->head];
        for (int cnt = 0; cnt < elem_arr->arr[elem].lst->size; cnt++) {
            int idx = (int)ptr_elem->data;
            if (--elem_arr->arr[idx].count == 0) 
                ins_at_the_end(output_q, idx);

            ptr_elem = &elem_arr->arr[elem].lst->arr[ptr_elem->next];
        }

        del_elem(output_q, output_q->head);
    }

    list_dtor(output_q);

    return rem;
}