/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode* prev = &dummy;
  struct ListNode* cur = head;

  struct ListNode little;
  struct ListNode* littleCur = &little;

  while (cur) {
    if (cur->val >= x) {
      prev = cur;
      cur = cur->next;
    } else {
      prev->next = cur->next;
      littleCur->next = cur;
      littleCur = cur;
      cur = cur->next;
    }
  }
  littleCur->next = dummy.next;
  return little.next;
}
