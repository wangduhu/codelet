
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

/*
  Status: Accepted (208/208)
  Runtime: 7 ms, faster than 87.83% of C++ submissions.
  Memory Usage: 14.8 MB, less than 81.34% of C++ submissions.
 */
