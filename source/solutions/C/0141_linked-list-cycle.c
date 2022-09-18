/* O(n), O(1) */
bool hasCycle(struct ListNode *head) {
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode* slow = &dummy;
  struct ListNode* fast = &dummy;
  while (slow->next && fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}
