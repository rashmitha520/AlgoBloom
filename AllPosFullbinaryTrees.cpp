/*
eg: 7
when k=1 , then l=func(1),r=func(7-1-1)
when k=2 ,then l=func(2) as n=2 and even numbers dont form full binary trees ,the recursive function returns empty array.
when k=3, l=func(3),r=func(7-3-1)
when k=4 same as k=2
when k=5 then l=func(5) r=func(1)
k=1---->
 
 0                       
/ \
0  0
  / \
 0   0     
/\
0 0  left or right depending on recursion

*/
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
