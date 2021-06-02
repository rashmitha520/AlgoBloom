 ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* odd=head,*even=head->next,*evenH=even;
        while(even and even->next)
        {
            odd->next=even->next;//put odd onces 
            odd=odd->next;//go to the next
            even->next=odd->next;//put the next even one after odd
            even=even->next;
        }
        odd->next=evenH;
        return head;
     }
