
/*You are given the root of a binary tree with n nodes where each node in the tree has node.val coins and there are n coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another. (A move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.

 

Example 1:


Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
*/
 
 <img src="https://assets.leetcode.com/users/votrubac/image_1548011422.png">             
             

class Solution {
public:
    int ans=0;
    int distributeCoins(TreeNode* root) {
       dfs(root);
        return ans;
    }
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int  l=dfs(root->left);
        int r= dfs(root->right);
        ans=ans+abs(r)+abs(l);
        return root->val+l+r-1;
    }
};
