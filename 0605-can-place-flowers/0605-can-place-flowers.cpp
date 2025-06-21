class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int i = 0;

        while (i < size) {
            // If current plot is 0 and (left is empty or boundary) and (right is empty or boundary)
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;  // Place flower
                n--;
                i += 2; // Skip next plot
            } else {
                i++;
            }
        }

        return n <= 0;
    }
};
