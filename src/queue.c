#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue queue = {.input_item = NULL, .output_item = NULL, .add = add, .get = get, .is_empty = is_empty};

void add(void *item)
{
    struct element *e = malloc(sizeof(struct element));
    e->data = item;

    if (queue.input_item == NULL)
    {
        e->next_element = NULL;
        queue.input_item = queue.output_item = e;

        return;
    }

    e->next_element = queue.input_item;
    queue.input_item = e;
}

void *get()
{
    if (queue.output_item == NULL)
        return NULL;

    void *data = queue.output_item->data;
    struct element *e = queue.input_item;
    struct element *old_e = e;

    while (e->next_element != NULL)
    {
        e = e->next_element;

        if (e->next_element != NULL)
            old_e = e;
        else
            break;
    }

    queue.output_item = old_e;
    queue.output_item->next_element = NULL;

    return data;
}

int is_empty()
{
    return queue.output_item == NULL ? 1 : 0;
}