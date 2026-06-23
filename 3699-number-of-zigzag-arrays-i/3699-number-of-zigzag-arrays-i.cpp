class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);
        vector<int> prefUp(m + 1), prefDown(m + 1);
        vector<int> nxtUp(m + 1), nxtDown(m + 1);

        // length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {
            prefUp[0] = prefDown[0] = 0;

            for (int v = 1; v <= m; v++) {
                prefUp[v] = prefUp[v - 1] + up[v];
                if (prefUp[v] >= MOD) prefUp[v] -= MOD;

                prefDown[v] = prefDown[v - 1] + down[v];
                if (prefDown[v] >= MOD) prefDown[v] -= MOD;
            }

            int totalUp = prefUp[m];

            for (int v = 1; v <= m; v++) {
                nxtUp[v] = prefDown[v - 1];

                nxtDown[v] = totalUp - prefUp[v];
                if (nxtDown[v] < 0) nxtDown[v] += MOD;
            }

            up.swap(nxtUp);
            down.swap(nxtDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans += up[v];
            ans += down[v];
        }

        return ans % MOD;
    }
};