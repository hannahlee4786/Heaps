#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // If went thru all items in list
  if (head == nullptr) {
    return;
  }
  // If value is larger than pivot
  if (head->val > pivot) {
    larger = head;
    larger->next = nullptr;
    llpivot(head->next, smaller, larger, pivot);
  }
  // If value is less than pivot
  if (head->val <= pivot) {
    smaller = head;
    smaller->next = nullptr;
    llpivot(head->next, smaller, larger, pivot);
  }
}
