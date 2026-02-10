class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int,int> freq;
            int evenDistinct = 0, oddDistinct = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];
                freq[x]++;

                if (freq[x] == 1) { // first occurrence
                    if (x % 2 == 0) evenDistinct++;
                    else oddDistinct++;
                }

                if (evenDistinct == oddDistinct) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
