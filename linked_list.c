#include "linked_list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define the Node
struct Node {
  int32_t data;
  struct Node *next;
};

// Function to create a new node
Node *create_node(int32_t data) {
  Node *new_node = malloc(sizeof(Node));
  if (!new_node) {
    fprintf(stderr, "[ERROR]: Memory Initialization\n");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_first(Node **head, int32_t data) {
  Node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_last(Node **head, int32_t data) {
  Node *new_node = create_node(data);
  if (!*head) {
    *head = new_node;
  } else {
    Node *current = *head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Function to insert a node at a specific index in the linked list
void insert(Node **head, uint32_t index, int32_t data) {
  Node *new_node = create_node(data);
  if (!*head) {
    *head = new_node;
    return;
  }
  if (index == 0) {
    new_node->next = *head;
    *head = new_node;
    return;
  }
  Node *current = *head;
  for (size_t i = 0; i < index - 1; ++i) {
    if (!current->next) {
      fprintf(stderr, "[ERROR]: Index Out of Bounds\n");
      free(new_node);
      return;
    }
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
}

// Function to delete a node at a specific index in the linked list
void delete_by_index(Node **head, uint32_t index) {
  if (!*head) {
    fprintf(stderr, "[ERROR]: List is Empty\n");
    return;
  }
  Node *temp = *head;
  if (index == 0) {
    *head = temp->next;
    free(temp);
    return;
  }
  Node *prev = NULL;
  for (size_t i = 0; i < index; ++i) {
    if (!temp) {
      fprintf(stderr, "[ERROR]: Index Out of Bounds\n");
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  if (!temp) {
    fprintf(stderr, "[ERROR]: Index Out of Bounds\n");
    return;
  }
  prev->next = temp->next;
  free(temp);
}

// Function to delete a node by value in the linked list
void delete_by_value(Node **head, int32_t value) {
  if (!*head) {
    fprintf(stderr, "[ERROR]: List is Empty\n");
    return;
  }
  Node *temp = *head;
  Node *prev = NULL;
  if (temp && temp->data == value) {
    *head = temp->next;
    free(temp);
    return;
  }
  while (temp && temp->data != value) {
    prev = temp;
    temp = temp->next;
  }
  if (!temp) {
    fprintf(stderr, "[ERROR]: Value Not in List\n");
    return;
  }
  prev->next = temp->next;
  free(temp);
}

// Function to traverse and print the linked list
void traverse(Node *head) {
  Node *current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  putchar('\n');
}

// Function to free all nodes in the linked list
void free_node(Node *head) {
  Node *current = head;
  Node *next_node;
  while (current) {
    next_node = current->next;
    free(current);
    current = next_node;
  }
}
