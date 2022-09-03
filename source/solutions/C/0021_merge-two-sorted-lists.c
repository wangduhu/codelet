/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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

/*
  Status: Accepted (208/208)
  Runtime: 8 ms, faster than 33.28% of C submissions.
  Memory Usage: 6 MB, less than 95.41% of C submissions.
 */
