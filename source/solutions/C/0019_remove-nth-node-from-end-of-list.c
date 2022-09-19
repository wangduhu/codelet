struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode *front = head;
  while (n-- > 0 && front) {
    front = front->next;
  }
  if (front == NULL) {
    struct ListNode *ans = head->next;
    head->next = NULL;
    return ans;
  }

  struct ListNode dummy;
  dummy.next = head;
  struct ListNode *prev = &dummy;
  struct ListNode *back = head;
  while (front) {
    front = front->next;
    back = back->next;
    prev = prev->next;
  }

  prev->next = back->next;
  back->next = NULL;
  return head;
}
