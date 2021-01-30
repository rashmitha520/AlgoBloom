/*
3----------------|
/\
2 5--------------|
\
 9---------------|
 right view: 3,5,9*/


class Solution {
public:
    void h(TreeNode* root,int l,vector<int>& v)
    { 
        if(!root) return;
            if(v.size()<=l)
            {
                v.push_back(root->val);
                
            }
        //records the right ones 
        h(root->right,l+1,v);
        // records the sole left ones with highest levels and right ones as null eg: 9 
         h(root->left,l+1,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return {};
        h(root,0,v);
        return v;
    }
};
