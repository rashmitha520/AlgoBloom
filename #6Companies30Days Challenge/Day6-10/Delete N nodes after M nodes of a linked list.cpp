   void linkdelete(struct Node  *head, int m, int n)
    {
        //Add code here
        
        Node* temp=head;
        while(temp)
        {
        int c=1;
        while(temp && c<m) {temp=temp->next;c++;}
        if(!temp) return;
        c=1;
        Node* t=temp->next;
        while(t && c<=n){t=t->next;c++;}
        temp->next=t;
        temp=t;
        }
        
        
    }
