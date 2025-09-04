class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSquared = 0;
        int maxArea = 0;

        for (const auto& dim : dimensions) {
            int length = dim[0];
            int width = dim[1];

            int currentDiagonalSquared = length * length + width * width;
            int currentArea = length * width;

            if (currentDiagonalSquared > maxDiagonalSquared) {
                maxDiagonalSquared = currentDiagonalSquared;
                maxArea = currentArea;
            } else if (currentDiagonalSquared == maxDiagonalSquared) {
                if (currentArea > maxArea) {
                    maxArea = currentArea;
                }
            }
        }
        return maxArea;
    }
};