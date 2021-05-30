int find(TreeNode* root,int& res) {
     if(!root) return 0;
     int lsum=find(root->left,res);
     int rsum=find(root->right,res);
     res+=abs(lsum-rsum); //calculates sum of tilts of each node
      
     return root->val + lsum + rsum;
    }
    int findTilt(TreeNode* root)
    { int tilts=0;
        find(root,tilts);
        return tilts;
    }
