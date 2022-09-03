#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0) : val(x), next(nullptr) {}

  bool equal_to(std::vector<int> nums) {
    std::vector<int>::iterator it = nums.begin();
    ListNode* cur = this;
    while (cur && it != nums.end()) {
      if (cur->val != *it) break;
      cur = cur->next;
      it++;
    }

    return cur == nullptr && it == nums.end();
  }

  ListNode* tail() {
    ListNode* cur = this;
    while (cur->next) {
      cur = cur->next;
    }
    return cur;
  }
};

ListNode* make_list(const std::vector<int>);
void free_list(ListNode*);
void print_list(ListNode*);
std::ostream& operator<<(std::ostream& out, ListNode* head);
bool operator== (ListNode* head, const std::vector<int>& nums);
void print_list(ListNode* l);

#endif
