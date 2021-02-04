/*Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?*/
#include<map>
 map<int ,int > m;

int solve(int n,vector<int>a){
    for(int i=0;i<=1005;i++)
{
    m[i]=0;
}
 for(int i=0;i<n;i++)
{
    m[a[i]]++;
}
    
    vector<int> dp(1005,0);
     //dp[0]=0 and dp[1]=no of m[a[1]]*m[a[1]] as it is obviously >= 0 as it is non negative
    dp[1]=m[1];
    for(int i=2;i<=1000;i++)
    {
        dp[i]=max(dp[i-2]+i*m[i],dp[i-1]);
    }
    return dp[1000];

}
