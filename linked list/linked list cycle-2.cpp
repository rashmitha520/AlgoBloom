/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(!head || !head->next) return nullptr;
        int index=0;ListNode *e=head;
        ListNode *slow=head,*fast=head;
       
        while(fast->next && fast->next->next)
        {
             slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
            while(slow!=e)
            {   slow  = slow->next;
                e=e->next;
            }
            return e;
            }
           
            
        }
        return nullptr;
    }
};
 
