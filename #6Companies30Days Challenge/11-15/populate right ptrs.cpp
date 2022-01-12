
class Solution {
public:
    Node* connect(Node* root) {
      if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* cur = nullptr;
            int n=q.size();
            for(int i=n;i;i--){
                auto node = q.front();q.pop();
                node->next = cur;
                cur=node;
                if(node->right) {
                q.push(node->right);
                q.push(node->left);
                                }
            }
            
        }
        return root;
    }
};
