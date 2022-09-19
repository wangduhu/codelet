struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode *cur = &dummy;
  int pos = 1;
  while (pos < left) {
    cur = cur->next;
    pos++;
  }
  struct ListNode *leading = cur;

  cur = leading->next;
  struct ListNode *post = NULL;
  while (pos < right) {
    post = cur->next;
    cur->next = post->next;
    post->next = leading->next;
    leading->next = post;
    pos++;
  }

  return dummy.next;
}
