class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int mx = *max_element(costs.begin(), costs.end());

        vector<int> freq(mx + 1, 0);

        for (int x : costs)
            freq[x]++;

        int ans = 0;

        for (int cost = 1; cost <= mx; cost++) {

            while (freq[cost] > 0 && coins >= cost) {
                coins -= cost;
                freq[cost]--;
                ans++;
            }
        }

        return ans;
    }
};