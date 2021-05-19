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
    int length(ListNode* head)
    {   int c=0;
        ListNode* slow=head,*fast=head;
        while(slow && fast->next)
        {
            slow=slow->next;
           // fast=fast->next->next;
            c++;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(length(head)<k) return head;
        int count=0;
        ListNode* prev=NULL;ListNode* next=NULL;ListNode* curr=head;
        while(curr && count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(curr) head->next=reverseKGroup(curr,k);
        return prev;
    }
};
