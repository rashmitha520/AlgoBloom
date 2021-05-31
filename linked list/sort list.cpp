//merging  
ListNode* merge(ListNode* fir,ListNode* sec)
    {
        ListNode dummy(0);
        ListNode* sent=&dummy;
        while(fir && sec)
        {
            if(fir->val<sec->val)
            {
                sent->next=fir;
                fir=fir->next;
            }
            else
            {
                sent->next=sec;
                sec=sec->next;
            }
            sent=sent->next;
        }
        if(fir) sent->next=fir;
        else sent->next=sec;
        return dummy.next;
        
    }
//gettuing mid
    ListNode* getm(ListNode* head)
    {   if(!head or !head->next) return nullptr;
        ListNode* slow=head,*fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
      ListNode* mid = slow->next;//doubt
        slow->next = nullptr;
        return mid;
    }

    ListNode* sortList(ListNode* head) {
      if(!head or !head->next) return head;
      ListNode* mid = getm(head);
      ListNode* left= sortList(head);//1st half
      ListNode* right= sortList(mid);//2nd half
      return merge(left,right);
        
    }
