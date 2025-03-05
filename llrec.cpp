#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // If went thru all items in list
  if (head == nullptr) {
    return;
  }

  Node* temp = head->next;

  // If value is larger than pivot
  if (head->val > pivot) {
    head->next = larger;
    larger = head;
  }
  // If value is less than pivot
  else if (head->val <= pivot) {
    head->next = smaller;
    smaller = head;
  }
  head = temp;
  llpivot(head, smaller, larger, pivot);
}
