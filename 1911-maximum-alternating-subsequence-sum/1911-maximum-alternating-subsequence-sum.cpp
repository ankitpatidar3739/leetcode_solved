class Solution {
public:
    typedef long long ll;
    ll solve(int idx,vector<int>& nums,bool flag,vector<vector<long long>>& dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        ll nottake=solve(idx+1,nums,flag,dp);

        ll take;
        if(flag){
            take=nums[idx]+solve(idx+1,nums,false,dp);
        }else{
            take=-nums[idx]+solve(idx+1,nums,true,dp);
        }
        return dp[idx][flag]=max(take,nottake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
       vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));

        return solve(0,nums,true,dp);
    }
};