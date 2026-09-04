class Solution {
public:
    int func(int i,vector<int>& nums,int t,vector<vector<int>>& dp){
        if(i==0){
            if(t%nums[0]==0) return t/nums[0];
            return 1e9;
        }
        if(dp[i][t]!=-1) return dp[i][t];

        int notake=0+func(i-1,nums,t,dp);
        int take=1e9;
        if(t>=nums[i]) take=1+func(i,nums,t-nums[i],dp);
        return dp[i][t]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans= func(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        else return ans;
    }
};