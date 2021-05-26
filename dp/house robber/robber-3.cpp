//tle
 int help(TreeNode* root)
    {
        if(!root) return 0;
        int cons=root->val,notc;
        if(root->left) cons+=help(root->left->right)+help(root->left->left);
        if(root->right) cons+=help(root->right->left)+help(root->right->right);
        notc=help(root->left)+help(root->right);
        return max(notc,cons);
    }
    int rob(TreeNode* root) {
     int ans= help(root);
        return ans;
    }

//memoization
class Solution {
public://memo
    map<TreeNode*,int> dp;
    int help(TreeNode* root)
    {
        if(!root) return 0;
      
        if(dp[root]) return dp[root];
      
        int cons=root->val,notc;
      
        if(root->left) cons+=help(root->left->right)+help(root->left->left);
      
        if(root->right) cons+=help(root->right->left)+help(root->right->right);
      
        notc=help(root->left)+help(root->right);
      
        int ans= max(notc,cons);
        return dp[root]=ans;
    }
    int rob(TreeNode* root) {
     int ans= help(root);
        return ans;
    }
};

//Easy method but not for interviews
vector<int> help(TreeNode* root)
    {
        if(!root) return {0,0};
        vector<int> left=help(root->left);
        vector<int> right=help(root->right);
        vector<int> res(2);
        res[0] =left[1]+ root->val +right[1];
        res[1] = max(left[0],left[1])+max(right[0],right[1]);
       
        return res;
    }
    int rob(TreeNode* root) {
     vector<int> ans= help(root);
        return max(ans[0],ans[1]);
    }
