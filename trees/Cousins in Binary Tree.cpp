/*In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.*/
//1st 
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,pair<int,int>> m;
        h(root,0,-1,m);
        return m[x].first==m[y].first && m[y].second!=m[x].second;
    }
    void h(TreeNode* root, int d,int parent,unordered_map<int,pair<int,int>>& m)
    {
        if(!root) return;
        m[root->val]={d,parent};
        h(root->left,d+1,root->val,m);
        h(root->right,d+1,root->val,m);
    }
};
//2nd
class Solution {
public:
    int xp,yp,xd,yd;
    bool isCousins(TreeNode* root, int x, int y) {
        
        h(root,x,y,0,0);
        return xd==yd && xp!=yp;
    }
    void h(TreeNode* root, int x,int y,int d,int m)
    {
        if(!root) return;
        if(x==root->val)
        {
          xd=d;
            xp=m;
        }
        if(y==root->val)
        {
          yd=d;
            yp=m;
        }
        h(root->left,x,y,d+1,root->val);
        h(root->right,x,y,d+1,root->val);
    }
};
