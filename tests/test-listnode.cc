#include "listnode.h"

#include <cassert>


int main(int argc, char *argv[])
{
    ListNode* l = make_list({1, 2, 3});

    print_list(l);

    assert(l->val == 1 && l->next->val == 2
           && l->next->next->val == 3
           && l->next->next->next == nullptr);

    assert(l->equal_to({1, 2, 3}));

    free_list(l);

    return 0;
}
