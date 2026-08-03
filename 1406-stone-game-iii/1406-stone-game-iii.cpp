class Solution {
public:
    vector<int> dp;
    vector<int> stone;
    int n;

    int dfs(int i) {
        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int sum = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stone[i + k];
            ans = max(ans, sum - dfs(i + k + 1));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        stone = stoneValue;
        n = stone.size();

        dp.assign(n, INT_MIN);

        int diff = dfs(0);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};