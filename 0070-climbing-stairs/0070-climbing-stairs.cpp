class Solution {
    private:

    int func(vector<int>&dp,int n){
        if(n==0) return 1;
        if(n==1) return 1;
        

        if(dp[n]!=-1) return dp[n];

        int left=func(dp,n-1);
        int right=func(dp,n-2);

        return dp[n]=left+right;
    }
public:
    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       return func(dp,n);
    }
};