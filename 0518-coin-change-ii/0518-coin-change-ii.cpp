class Solution {
    private:
    int func(int idx,vector<int>& coins,int t,vector<vector<int>>& dp){
        if(t==0) return 1;
        if(idx>=coins.size()) return 0;

        if(dp[idx][t]!=-1) return dp[idx][t];
        int notpick=func(idx+1,coins,t,dp);
        int pick=0;
        if(coins[idx]<=t) pick=func(idx,coins,t-coins[idx],dp);

        return dp[idx][t]=notpick+pick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return func(0,coins,amount,dp);
    }
};