struct ListNode *deleteDuplicates(struct ListNode *head) {
  struct ListNode dummy;
  dummy.next = head;
  dummy.val = head ? (head->val - 1) : 0;
  struct ListNode *prev = &dummy;
  struct ListNode *cur;
  while (prev && prev->next) {
    cur = prev->next;
    if (cur->val != prev->val) {
      prev = cur;
      cur = cur->next;
    } else {
      while (cur && (cur->val == prev->val)) {
        cur = cur->next;
      }
      prev->next = cur;
      prev = cur;
    }
  }
  return dummy.next;
}
