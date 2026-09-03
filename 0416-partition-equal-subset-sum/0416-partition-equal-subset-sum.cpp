class Solution {
public:
    bool func(int idx,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(target==0) return true;
        if(idx==0) return (target==nums[idx]);

        if(dp[idx][target]!=-1) return dp[idx][target];

        bool nottake=func(idx-1,nums,target,dp); 
        bool take=false;
        if(nums[idx]<=target) take=func(idx-1,nums,target-nums[idx],dp);

        return dp[idx][target]= take | nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        int k=(sum/2);
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        if(sum%2!=0) return false;
        else return func(n-1,nums,k,dp);
    }
};