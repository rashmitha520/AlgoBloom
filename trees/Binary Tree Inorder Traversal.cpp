//recursive


class Solution {
public:
     vector<int> inorderTraversalh(TreeNode* root,  vector<int>& le)
     {
         if(root && root->left)
            inorderTraversalh(root->left,le);
        if(root)
            le.push_back(root->val);
        if(root && root->right)
             inorderTraversalh(root->right,le);
        return le;
     }
         
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> le;   
        inorderTraversalh(root,le);
        
        return le;
       
    }
    
};

//stack - iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode*> s;
      vector<int> ans;
      TreeNode* cur=root;
      while(cur || !s.empty())
      {
          while(cur)
          {
              s.push(cur);
              cur=cur->left;
          }
          cur=s.top();
          s.pop();
          ans.push_back(cur->val);
          cur=cur->right;
      }
        return ans;
    }
};
//morris traversal
