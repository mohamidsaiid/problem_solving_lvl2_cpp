// https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapp(ListNode* p)
    {
        if(p == nullptr || p->next == nullptr) return p;
        ListNode* t = p->next;
        p->next = swapp(p->next->next);
        t->next = p;
        return t;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        head = swapp(head);
        return head; 
    }
};
