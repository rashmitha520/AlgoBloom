class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* head=new  ListNode(0);
         ListNode* p=l1,*q=l2,*cur=head;int carry=0;
        while(p || q)
        { //if not existing then give 0
            int x=(p)?p->val:0;
            int y=(q)?q->val:0;
            
            int sum=x+y+carry;
            
            carry=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            if(p) p=p->next;
            if(q) q=q->next;
            
        }
        if(carry>0)
        {
            cur->next=new ListNode(carry);
        }
        return head->next;
    }
};

//better approach
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode c1 = l1;
        ListNode c2 = l2;
        ListNode sentinel = new ListNode(0);
        ListNode d = sentinel;
        int sum = 0;
        while (c1 != null || c2 != null) {
            sum /= 10;
            if (c1 != null) {
                sum += c1.val;
                c1 = c1.next;
            }
            if (c2 != null) {
                sum += c2.val;
                c2 = c2.next;
            }
            d.next = new ListNode(sum % 10);
            d = d.next;
        }
        if (sum / 10 == 1)
            d.next = new ListNode(1);
        return sentinel.next;
    }
}
