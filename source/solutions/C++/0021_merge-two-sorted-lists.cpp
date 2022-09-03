class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode dummy;
      ListNode *cur = &dummy;
      if ((list1 == nullptr) && (list2 == nullptr)) {
        return nullptr;
      }
      while ((list1 != nullptr) || (list2 != nullptr)) {
        if (list1 == nullptr) {
          cur->next = list2;
          break;
        }
        if (list2 == nullptr) {
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
};
