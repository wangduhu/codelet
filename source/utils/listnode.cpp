#include <iostream>
#include <vector>

#include "listnode.h"

using namespace std;

ListNode* make_list(const std::vector<int> nums) {
    ListNode dummy;
    ListNode* cur = &dummy;
    for (vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); it++) {
        cur->next = new ListNode(*it);
        cur = cur->next;
    }
    return dummy.next;
}


void free_list(ListNode* l) {
    while (l) {
        ListNode* cur = l;
        l = cur->next;
        delete l;
    }
}

ostream& operator<<(ostream& out, ListNode* head) {
    while (head) {
        out << head->val << ' ';
        head = head->next;
    }
    return out;
}

bool operator== (ListNode* head, const std::vector<int>& nums) {
    auto it = nums.cbegin();
    while (head && it != nums.cend()) {
        if (head->val != *it) return false;
        head = head->next;
        it++;
    }
    return head == nullptr && it == nums.cend();
}

void print_list(ListNode* l) {
    cout << l->val;
    ListNode* cur = l->next;
    while (cur) {
        cout << "->" << cur->val;
        cur = cur->next;
    }
    cout << endl;
}
