class Solution {
    
public:
    int func(int idx,int k,vector<int>& prices,int tn,vector<vector<int>> &dp){
        int n=prices.size();
        if(idx==n || tn==2*k) return 0;

        if(dp[idx][tn]!=-1) return dp[idx][tn];

        if(tn%2==0){
            return dp[idx][tn]=max(-prices[idx]+func(idx+1,k,prices,tn+1,dp),func(idx+1,k,prices,tn,dp));
        }
        return dp[idx][tn]=max(prices[idx]+func(idx+1,k,prices,tn+1,dp),func(idx+1,k,prices,tn,dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));

        return func(0,k,prices,0,dp);
    }
};