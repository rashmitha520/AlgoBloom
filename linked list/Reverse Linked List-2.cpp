  ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=head,*prev=nullptr,*third=NULL;
        if(!head) return nullptr;
        while(left>1)
        {
            prev=temp;
            temp=temp->next;
            left--;
            right--;
        }
      ListNode* tail=temp,*con=prev;
        while(right>0)
        {   third=temp->next;
             temp->next=prev;
              prev=temp;
              temp=third;
            right--;
        }
       if(con)
           con->next=prev;
        else
            head=prev;
        tail->next=temp;
        return head;
    }
