//best approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy1,buy2,pro1,pro2;
        buy1 = INT_MAX,buy2=INT_MAX,pro1=INT_MIN,pro2=INT_MIN;
        for(int i=0;i<n;i++)
        {   //1st purchase
            buy1= min(buy1,prices[i]);
            //1st profit
            pro1=max(pro1,prices[i]-buy1);
            //amt spent on 2nd buy : prices[i]-(profit from 1st buy)
             buy2= min(buy2,prices[i]-pro1);
            //profit 2 : prices[i]-2nd buy+profit from 1st purchase
            pro2=max(pro2,prices[i]-buy2);
        }
        return pro2;
    }
};
