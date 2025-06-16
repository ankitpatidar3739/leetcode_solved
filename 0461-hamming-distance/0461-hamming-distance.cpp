class Solution {
public:
    int hammingDistance(int x, int y) {
    int ans=x^y;

    return __popcount(ans);
    }
};