class Solution {
public:
    /* 
    1. reverse ll
    2. add them 
    3. return reverse
    */
    ListNode* reverse(ListNode* l)
    {
        
          ListNode* current = l;
          ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        l = prev; 
        
        return l;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* p=reverse(l1);
          ListNode* q=reverse(l2);
        int carry=0; ListNode* dum=new ListNode(0);
        ListNode* cur=dum;
        while(p||q)
        {
            int sum=(p?p->val:0)+(q?q->val:0)+carry;
            carry=sum/10;
            cur->next = new ListNode(sum%10);
            cur=cur->next;
           if(p) p=p->next;
           if(q) q=q->next;
        }
        if(carry==1) cur->next=new ListNode(1);
       return reverse(dum->next);
    }
};


//stacks approach
class Solution {
public:
    ListNode* reverse(ListNode* l)
    {
        ListNode* cur=l; ListNode* prev=NULL,*next=NULL;
        while(cur)
        {
          next=cur->next;
          cur->next=prev;
            prev=cur;
            cur =next;
            
        }
        l=prev;
        return l;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int> s1,s2;ListNode* du=new ListNode(0);
        ListNode* cu=du;
        while(l1)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;
        while(!s1.empty() || !s2.empty())
        {
           int sum= (!s1.empty()?s1.top():0)  +  (!s2.empty()?s2.top():0) +carry; 
            carry = sum/10;
            cu->next=new ListNode(sum%10);
           if(!s1.empty()) s1.pop(); 
           if(!s2.empty()) s2.pop();
            cu=cu->next;
        }
        if(carry==1) cu->next=new ListNode(1);
        return reverse(du->next);
    }
};
