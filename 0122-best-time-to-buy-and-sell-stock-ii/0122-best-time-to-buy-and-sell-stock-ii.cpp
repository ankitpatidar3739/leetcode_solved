class Solution {
public:
    int func(int idx,int buy,int n,vector<int> &prices,vector<vector<int>> &dp){
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        long profit=0;
        if(buy){
            profit+=max(-prices[idx]+func(idx+1,0,n,prices,dp),0+func(idx+1,1,n,prices,dp));
        }else{
            profit+=max(prices[idx]+func(idx+1,1,n,prices,dp),0+func(idx+1,0,n,prices,dp));
        }
        return dp[idx][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return func(0,1,n,prices,dp);
    }
};