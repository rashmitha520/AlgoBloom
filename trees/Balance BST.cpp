void store(TreeNode* root,vector<TreeNode*>& nodes)
    {
        if(!root) return;
        store(root->left,nodes);
        nodes.push_back(root);
        store(root->right,nodes);
    }
    TreeNode* bal(vector<TreeNode*>& nodes,int s,int e)
    {
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* root =nodes[mid]; //binary search
        root->left=bal(nodes,s,mid-1);//left elements to left
        root->right=bal(nodes,mid+1,e);//right to right
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
       vector<TreeNode*> nodes;
        //store in sorted order in array
        store(root,nodes);
        return bal(nodes,0,nodes.size()-1);
    }
