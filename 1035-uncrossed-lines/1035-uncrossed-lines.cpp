class Solution {
public:
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2,
               vector<vector<int>>& dp)
    {
        if(i == nums1.size() || j == nums2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(nums1[i] == nums2[j])
            return dp[i][j] = 1 + helper(i + 1, j + 1, nums1, nums2, dp);

        return dp[i][j] = max(helper(i + 1, j, nums1, nums2, dp),
                              helper(i, j + 1, nums1, nums2, dp));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(0, 0, nums1, nums2, dp);
    }
};