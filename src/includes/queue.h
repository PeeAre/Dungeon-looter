#ifndef QUEUE_H
#define QUEUE_H

struct element
{
    void *data;
    struct element *next_element;
};

typedef struct
{
    struct element *input_item;
    struct element *output_item;
    void (*add)(void *item);
    void *(*get)(void);
    int (*is_empty)(void);
} Queue;

extern Queue queue;
void add(void *item);
void *get();
int is_empty();

#endif