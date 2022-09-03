struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode dummy;
  struct ListNode *cur = &dummy;
  if ((list1 == NULL) && (list2 == NULL)) {
      return NULL;
  }
  while ((list1 != NULL) || (list2 != NULL)) {
    if (list1 == NULL) {
      cur->next = list2;
      break;
    }
    if (list2 == NULL) {
      cur->next = list1;
      break;
    }
    if (list1->val < list2->val) {
      cur->next = list1;
      list1 = list1->next;
    } else {
      cur->next = list2;
      list2 = list2->next;
    }
    cur = cur->next;
  }
  return dummy.next;
}
