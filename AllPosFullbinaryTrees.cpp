??
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
     vector<TreeNode*> res;
        if(N%2==0) return res;
        
        if(N==1) {
            res.push_back(new TreeNode(0));
            return res;
        };
        for(int k=1;k<N;k+=2)
        {  //have used k for k left nodes
            vector<TreeNode*> l=allPossibleFBT(k);
            //for n-k-1 right nodes
             vector<TreeNode*> r=allPossibleFBT(N-k-1);
            
            for(auto i:l)
                for(auto j:r)
                {
                   TreeNode* root=new TreeNode(0);
                    root->left=i;root->right=j;
                    res.push_back(root);
                    
                }
        }
        return res;
    }
};
