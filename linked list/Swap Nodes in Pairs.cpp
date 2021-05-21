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
    ListNode* swapPairs(ListNode* head) {
         if(length(head)<2) return head;
        int count=0;
        ListNode* prev=NULL;ListNode* next=NULL;ListNode* curr=head;
        while(curr && count<2)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(curr) head->next=swapPairs(curr);
        return prev;
    }
};
