class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxprofit=0;

        for(int i=0;i<prices.size();i++){
            int cost=prices[i]-mini;
            maxprofit=max(cost,maxprofit);
            mini=min(prices[i],mini);
        }
         return maxprofit;
    }
};