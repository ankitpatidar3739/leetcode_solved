class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        
        std::vector<bool> basket_used(m, false);
        int placed_fruits_count = 0;
        
        for (int i = 0; i < n; ++i) {
            bool placed = false;
            for (int j = 0; j < m; ++j) {
                if (!basket_used[j] && baskets[j] >= fruits[i]) {
                    basket_used[j] = true;
                    placed_fruits_count++;
                    placed = true;
                    break; // Move to the next fruit
                }
            }
        }
        
        return n - placed_fruits_count;
    }
};