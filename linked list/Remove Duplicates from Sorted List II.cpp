/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
* Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      //  if(!head||!head->next) return head;
    ListNode* temp = head;
        //sentinel todo
        ListNode* sentinel = new ListNode(INT_MAX);
        sentinel->next=head;
        ListNode* prev = sentinel;
      
        while(temp!=nullptr)
        { 
            
            if(temp->next && temp->next->val==temp->val)
            {
                
                while(temp->next && temp->next->val==temp->val)
                {
                    temp=temp->next;
                }
                 prev->next = temp->next;   
            }
            else{
                prev=prev->next;
            }
            temp=temp->next;
        }
        return sentinel->next;
        
    }
};
