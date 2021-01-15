/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.*/

#include<bits/stdc++.h>
#include<climits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int i=0,j=prices.size();int maxi=0;int mini=INT_MAX;       
        while(i<prices.size()){
        mini=min(mini,prices[i]);
        maxi=max(maxi,prices[i]-mini);
            i++;
        }
        return maxi;
    }
};
