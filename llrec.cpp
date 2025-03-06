#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // If went thru all items in list
  if (head == NULL) {
    smaller = NULL;
    larger = NULL;
    return;
  }

  // Create temporary node for head->next
  Node* temp = head->next;
  head->next = NULL; // Breaks link

  // If value is larger than pivot
  if (head->val > pivot) {
    larger = head;
    llpivot(temp, smaller, larger->next, pivot);
  }
  // If value is less than pivot
  else if (head->val <= pivot) {
    smaller = head;
    llpivot(temp, smaller->next, larger, pivot);
  }
  head = NULL;
}
