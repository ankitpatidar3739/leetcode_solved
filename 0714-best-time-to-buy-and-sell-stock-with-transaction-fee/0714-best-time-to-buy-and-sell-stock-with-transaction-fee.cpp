class Solution {
public:
    int func(int idx,int buy,int n,vector<int> &prices,vector<vector<int>> &dp,int fee){
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        long profit=0;
        if(buy){
            profit+=max(-prices[idx]+func(idx+1,0,n,prices,dp,fee),0+func(idx+1,1,n,prices,dp,fee));
        }else{
            profit+=max(prices[idx]-fee+func(idx+1,1,n,prices,dp,fee),0+func(idx+1,0,n,prices,dp,fee));
        }
        return dp[idx][buy]=profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return func(0,1,n,prices,dp,fee);
    }
};