#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
struct Node typedef Node;

Node *create_node(int32_t data);
void insert_first(Node **head, int32_t data);
void insert_last(Node **head, int32_t data);
void insert(Node **head, uint32_t index, int32_t data);
void delete_by_index(Node **head, uint32_t index);
void delete_by_value(Node **head, int32_t value);
void traverse(Node *head);
void free_node(Node *head);
#endif // !LINKED_LIST_H
