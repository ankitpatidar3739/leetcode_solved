class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i + 1;

        while (j < n) {
            if (nums[i] == 0) {
                if (nums[j] != 0) {
                    swap(nums[i], nums[j]);
                    i++;
                }
                j++;
            } else {
                i++;
                if (j <= i) j = i + 1;
            }
        }
    }
};
