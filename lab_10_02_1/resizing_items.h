#ifndef LAB_10_RESIZING_ITEMS_H
#include "defines.h"

int create_fields(item_t *item, long int size_a, long int size_n, int c);
void remove_item(item_t *p, int n, int fullsize);
int resize_items_array(item_t **p, int *num, int flag);
void clear(item_t **p, int size);
#define LAB_10_RESIZING_ITEMS_H

#endif //LAB_10_RESIZING_ITEMS_H
