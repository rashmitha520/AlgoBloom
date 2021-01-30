/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
*/


class Solution {
public:
    int sum=INT_MIN;
     int h(TreeNode* root)
    {
        if(!root) return 0;
         //the option to choose the left or right subtree or whether i will just settle with my root value.
        int l=max(0,h(root->left));
        int r=max(0,h(root->right));
         int k=l+r+root->val;
         //check if max sum is prev sum or the tree/subtree itself?
        sum = max(sum,k);
         //choose either one of l,r as if both were giving max then that would be my max sum
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
      
        h(root);
        return sum;
        
    }
   
};
