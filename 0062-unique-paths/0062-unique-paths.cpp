class Solution {
  int func(int m,int n,vector<vector<int>>&dp){
    if(m==0 && n==0) dp[m][n]=1;
    if(m<0 || n<0) return 0;

    if(dp[m][n]!=0) return dp[m][n];
    int left=func(m,n-1,dp);
    int up=func(m-1,n,dp);

    return dp[m][n]=left+up;
  }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));

        return func(m-1,n-1,dp);
    }
};