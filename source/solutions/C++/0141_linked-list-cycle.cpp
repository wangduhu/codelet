class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast) {
      fast = fast->next;
      slow = slow->next;
      if (fast == nullptr)
        return false;
      fast = fast->next;
      if (fast == slow)
        return true;
    }
    return false;
  }
};
