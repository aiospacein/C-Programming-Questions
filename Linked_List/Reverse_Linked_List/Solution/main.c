

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct linklist_s {
  char data;
  struct linklist_s *head;
} linklist_s;

bool insert(linklist_s **llPtr, char *data) {
  linklist_s *node = (linklist_s *)malloc(sizeof(linklist_s));
  if (node != NULL) {
    node->data = *data;
    if (*llPtr != NULL) {
      node->head = *llPtr;
      *llPtr = node;
    } else {
      *llPtr = node;
      node->head = NULL;
    }
    return true;
  } else {
    printf("Memory Full \n");
    return 0;
  }
}

void delete(linklist_s **llPtr, char *data) {

  linklist_s *prev = NULL, *temp = *llPtr;
  while ((temp != NULL) && (temp->data != *data)) {
    prev = temp;
    temp = temp->head;
  }

  if (temp == NULL) {
    printf("Elemnet Not Found \n");
    return;
  }
  if (prev == NULL) {
    *llPtr = temp->head;
  } else {
    prev->head = temp->head;
  }
  free(temp);
}

void printll(linklist_s *llPtr) {
  while (llPtr != NULL) {
    printf("Data is %c \n", llPtr->data);
    llPtr = llPtr->head;
  }
}

void reverse(linklist_s **llPtr) {
  linklist_s *prev = NULL, *next = NULL, *temp = *llPtr;
  while (temp != NULL) {
    next = temp->head;
    temp->head = prev;
    prev = temp;
    temp = next;
  }
  *llPtr = prev;
}
int main(void) {
  linklist_s *head = NULL;

  printf("--- Setup: Building Initial List ---\n");
  insert(&head, "A");
  insert(&head, "B");
  insert(&head, "C");
  insert(&head, "D");
  printll(head); // Expected: D -> C -> B -> A

  printf("\n--- Testcase 8: Reverse Populated List ---\n");
  reverse(&head);
  printll(head); // Expected: A -> B -> C -> D

  printf("\n--- Testcase 9: Reverse Single Element List ---\n");
  // Clearing down to 1 element ('A') for testing
  delete(&head, "D");
  delete(&head, "C");
  delete(&head, "B");
  printll(head); // Expected: A

  reverse(&head);
  printll(head); // Expected: A (Should stay the same)

  printf("\n--- Testcase 10: Reverse Empty List ---\n");
  delete(&head, "A");
  printll(head); // Expected: List is empty.

  reverse(&head);
  printll(head); // Expected: List is empty. (Should safely do nothing)

  return 0;
}