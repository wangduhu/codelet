struct ListNode* recursive(struct ListNode* l) {
  if ((l == NULL) || (l->next == NULL)) {
    return l;
  }
  struct ListNode *next = l->next;
  l->next = NULL;
  struct ListNode *tail = recursive(next);
  next->next = l;
  return tail;
}

struct ListNode *reverseList(struct ListNode *head) {
  return recursive(head);
}

#if 0
struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode* prev = NULL;
  struct ListNode* cur = head;
  struct ListNode* next;
  while (cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode dummy = { 0 };
  while (head) {
    struct ListNode* next = head->next;
    head->next = dummy.next;
    dummy.next = head;
    head = next;
  }
  return dummy.next;
}
#endif
