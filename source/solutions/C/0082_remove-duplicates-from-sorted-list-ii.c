struct ListNode *deleteDuplicates(struct ListNode *head) {
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode *prev = &dummy;
  struct ListNode *cur = head;
  struct ListNode *post;
  while (cur && cur->next) {
    post = cur->next;
    if (cur->val != post->val) {
      prev = cur;
      cur = post;
      post = post->next;
    } else {
      while (post && post->val == cur->val) {
        post = post->next;
        cur = cur->next;
      }
      prev->next = cur->next;
      cur = cur->next;
    }
  }
  return dummy.next;
}
