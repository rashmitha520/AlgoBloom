//merge method
class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<=l2->val)
            {l1->next=merge(l1->next,l2); return l1;}
        else
          {  l2->next=merge(l1,l2->next); return l2;}
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        
        while(lists.size()>1)
        {
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};

//priority queue
    struct cmp
    {
        bool operator()(ListNode* a,ListNode* b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        if(lists.size()==0) return NULL;
        for(auto i:lists)
             if(i)  
              q.push(i);
        
        ListNode* head=new  ListNode(0);
         ListNode* temp=head;
        while(q.size()>0)
        {
            ListNode* cur=q.top();//take min val
            q.pop();
            temp->next=new ListNode(cur->val);//make it first node
            temp=temp->next;
            if(cur->next)//push the rest of 1st ll except 1st node of it
            q.push(cur->next);
        }
        return head->next;
        
    }
