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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        ListNode* curr=head;
        ListNode* prev;
        while(curr->val==val)
        {
            curr=curr->next;   
            if(!curr)
                return NULL;
        }
        head=curr;
        prev=curr;
        curr=curr->next;
        while(curr)
        {
            if(curr->val==val)
            {
                prev->next=curr->next;
            }
            else
            {
                prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};