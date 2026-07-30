class Solution {
public:

    // int f(int idx,vector<int>& nums,vector<int>& dp){
    //     if(idx==0) return nums[idx];
    //     if(idx<0) return 0;
    //     if(dp[idx]!=-1) return dp[idx];

    //     int pick=nums[idx]+f(idx-2,nums,dp);
    //     int notpick=f(idx-1,nums,dp);

    //     return dp[idx]=max(pick,notpick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);

        // return f(n-1,nums,dp);
        dp[0]=nums[0];

        for(int i=1;i<n;i++){
            int take=nums[i];if(i>1) take+=dp[i-2];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
};