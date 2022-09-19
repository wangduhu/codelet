struct ListNode *swapPairs(struct ListNode *head) {
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode *prev = &dummy;

  struct ListNode *odd = NULL;
  struct ListNode *even = NULL;
  struct ListNode *next = NULL;
  while (prev) {
    if ((prev->next == NULL) || (prev->next->next == NULL)) {
      break;
    }
    odd = prev->next;
    even = odd->next;
    next = even->next;

    odd->next = next;
    even->next = odd;
    prev->next = even;

    prev = odd;
  }

  return dummy.next;
}
