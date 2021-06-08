//hashmap
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       set<ListNode*> vis;
        while(headA)
        {
            vis.insert(headA);
            headA=headA->next;
        }
         while(headB)
        {
            if(vis.find(headB)!=vis.end()) return headB;
            headB=headB->next;
        }
        return NULL;
    }

//2ptr approach
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     ListNode *t1=headA; ListNode *t2=headB;
        
        while(t1!=t2)
        { 
            if(!t1) t1=headB;
            else  t1=t1->next;
            if(!t2) t2=headA;
            else t2=t2->next;
        }
        return t1;
    }
