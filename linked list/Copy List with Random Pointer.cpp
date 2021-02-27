class Solution {
public:
    void createll(Node*head){
        if(head==NULL) return;
        while(head!=NULL){
        Node* temp=head->next;
            head->next=new Node(head->val);
            head->next->next=temp;
            head=head->next->next;
        }
        
    }
    void randomass(Node *head,Node* newHead){
       Node*curr=newHead,*old=head;
        while(old!=NULL){
            if(old->random!=NULL)
            curr->random=old->random->next;
            else
                curr->random=NULL;
            if(curr->next!=NULL) curr=curr->next->next;
            old=old->next->next;
        }
    }
   Node* separate(Node* head,Node* newHead){
       Node* curr=newHead,*old=head;
        while(curr!=NULL){
          old->next=old->next->next;
            old=old->next;
            if(curr->next!=NULL)
                curr->next=curr->next->next;
            else
                curr->next=NULL;
            curr=curr->next;
        }
        return newHead;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        
        createll(head);
        randomass(head,head->next);
        return separate(head,head->next);
    }
};
