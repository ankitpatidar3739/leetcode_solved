class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;

        // Step 1: Find the maximum candies
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }

        // Step 2: Compare each kid's candies + extraCandies with maxCandies
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            result[i] = (candies[i] + extraCandies >= maxCandies);
        }

        return result;
    }
};
