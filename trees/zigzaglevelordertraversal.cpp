class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level=0;
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
          vector<vector<int>> res;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> v(n);
           //in for loop for each nodes
           for(int i=0;i<n;i++)
           {
               TreeNode* t=q.front();
               q.pop();
               if(level==0)
               v[i]=t->val;
               else
                   //reverse pushback when odd
                   v[n-i-1]=t->val;
               
               if(t->left) q.push(t->left);
               if(t->right) q.push(t->right);
           }
            res.push_back(v);
            //if level==0 then !level=1 and vice versa
            //for even it becomes 0 and odd its 1.
            level=!level;
        }
        return res;
    }
};
