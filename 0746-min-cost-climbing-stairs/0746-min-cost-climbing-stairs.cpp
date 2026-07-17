class Solution {
public:
    int func(vector<int>& cost,int i,vector<int>&dp){
        int n=cost.size();
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int one=cost[i]+func(cost,i+1,dp);
        int two=cost[i]+func(cost,i+2,dp);

        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(func(cost,0,dp),func(cost,1,dp));
    }
};