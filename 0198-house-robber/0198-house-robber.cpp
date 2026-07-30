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
        // vector<int>dp(n);

        // return f(n-1,nums,dp);
        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int take=nums[i];if(i>1) take+=prev2;
            int nottake=prev;
            int curr=max(take,nottake);

            prev2=prev;
            prev=curr;
            curr=prev2;
        }
        return prev;
    }
};