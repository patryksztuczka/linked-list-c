#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *next;
  int data;
} Node;

Node *head = NULL;

Node *add_node(int data) {
  Node *new = NULL;

  if (head == NULL) {
    new = malloc(sizeof(Node));
    if (new == NULL) {
      printf("Error");
      return NULL;
    }
    new->data = data;
    head = new;
    new->next = NULL;
  } else {
    new = malloc(sizeof(Node));
    if (new == NULL) {
      printf("Error");
      return NULL;
    }
    new->data = data;
    new->next = head;
    head = new;
  }

  return new;
}

int remove_node(int data) {
  Node *current = head;
  Node *prev = head;

  while (current != NULL) {
    if (current->data == data) {
      if (current == head) {
        head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      current = NULL;
      return 1;
    }
    prev = current;
    current = current->next;
  }

  return 0;
}

Node *insert_node(int data, int position) {
  Node *current = head;

  while (current != NULL && position != 0) {
    position--;
    current = current->next;
  }

  if (position != 0) {
    printf("Given position is to far from the list");
    return NULL;
  }

  Node *new = malloc(sizeof(Node));
  if (new == NULL) {
    return NULL;
  }
  new->data = data;
  new->next = current->next;
  current->next = new;

  return new;
}

void print_list() {
  Node *current = head;
  while (current != NULL) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("\n");
  return;
}

void print_menu() {
  printf("\nSelect operation:\n");
  printf("\t1. Add node to the list\n");
  printf("\t2. Remove node from the list\n");
  printf("\t3. Insert node to the list\n");
  printf("\t4. Print the list\n");
  printf("\t5. Exit\n");

  return;
}

int main() {
  int option = -1;
  int arg1 = 0;
  int arg2 = 0;

  while (option != 5) {
    print_menu();

    int result = scanf("%d", &option);

    if (result == 1 && option >= 1 && option <= 5) {
      switch (option) {
        case 1:
          printf("Pass data to insert:\n");
          scanf("%d", &arg1);
          Node *new = add_node(arg1);
          if (new == NULL) {
            printf("Failed to insert node");
          }
          break;
        case 2:
          printf("Pass data to remove:\n");
          scanf("%d", &arg1);
          int success = remove_node(arg1);
          if (success) {
            printf("Node removed");
          } else {
            printf("Node not found");
          }
          break;
        case 3:
          printf("Pass data to insert:\n");
          scanf("%d", &arg1);
          printf("Pass position:\n");
          scanf("%d", &arg2);
          Node *new2 = insert_node(arg1, arg2);
          if (new2 = NULL) {
            printf("Failed to insert node");
          }
          break;
        case 4:
          print_list();
          break;
        case 5:
          break;
        default:
          break;
      }
    }
  }

  return 0;
}