class Solution {
    private:
    long long func(int idx,int j,string &s,string &t,vector<vector<long long>>& dp){

        if(j == t.size()) return 1;
        if(idx == s.size()) return 0;

        if(dp[idx][j] != -1)
            return dp[idx][j];

       if(s[idx]==t[j]){
        long long  take=func(idx+1,j+1,s,t,dp);
        
        long long nottake=func(idx+1,j,s,t,dp);

        return dp[idx][j]=take+nottake;
       }else{
        return dp[idx][j]=func(idx+1,j,s,t,dp);
       }
    }
public:
    int numDistinct(string s, string t) {
        int sn=s.size();
        int tn=t.size();
        
        vector<vector<long long>>dp(sn,vector<long long>(tn,-1));
        return func(0,0,s,t,dp);
    }
};