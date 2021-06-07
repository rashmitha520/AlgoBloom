int length(ListNode* head)
    {   int c=0;
        ListNode* temp=head;
        while(temp)
        {
            temp=temp->next;c++;
        }
        return c;
        }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int k=length(head)-n+1;
        ListNode* temp=head,*prev=head;
        if(k==1) 
            return head->next;
        while(temp && k>0)
        {
            if(k==1)
            {
               if(temp->next==NULL) 
                  { prev->next=NULL;break;}
                else
                {
                    prev->next=temp->next;
                    
                }
            }
            prev=temp;
            temp=temp->next;
            k--;
        }
       return head;
    }
