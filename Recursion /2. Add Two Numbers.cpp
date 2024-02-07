// https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode *fun(ListNode *a, ListNode *b, int carry)
    {
        if(a == nullptr && b == nullptr && carry == 1) return new ListNode(1);
        if(a == nullptr && b == nullptr) return nullptr;
        int x = 0, y = 0;
        if(a)
            x = a->val;
        if(b) 
            y = b->val;
        int tot = y + x + carry;
        int ncarry = tot / 10;
        tot = tot % 10;
        ListNode *c = new ListNode(tot);
        c->next = fun(a ? a->next : nullptr,b ? b->next : nullptr, ncarry);
        return c; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return fun(l1, l2, 0);   
    }
};
