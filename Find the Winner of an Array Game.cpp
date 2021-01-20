class Solution {
public:
    int getWinner(vector<int>& a, int k) {
        int winner=a[0],c=0;
        for(int i=1;i<a.size();i++)
        {
            if(winner>a[i])
            {
                c+=1;
            }
            else
            {
                c=1;
                winner=a[i];
            }
            if(c==k) break;
        }
        return winner;
    }
};
