class Solution {
    // private:
    // int func(int idx,vector<int>& coins,int t,vector<vector<int>>& dp){
    //     if(t==0) return 1;
    //     if(idx>=coins.size()) return 0;

    //     if(dp[idx][t]!=-1) return dp[idx][t];
    //     int notpick=func(idx+1,coins,t,dp);
    //     int pick=0;
    //     if(coins[idx]<=t) pick=func(idx,coins,t-coins[idx],dp);

    //     return dp[idx][t]=notpick+pick;
    // }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        // return func(0,coins,amount,dp);

        vector<vector<long long>>dp(n+1,vector<long long>(amount+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int idx=n-1;idx>=0;idx--){
            for(int t=1;t<=amount;t++){
                long long notpick=dp[idx+1][t];
            long long pick=0;
            if(coins[idx]<=t) pick=dp[idx][t-coins[idx]];

            dp[idx][t]=min(1LL * INT_MAX, pick + notpick);
            }
        }
        return dp[0][amount];
    }
};