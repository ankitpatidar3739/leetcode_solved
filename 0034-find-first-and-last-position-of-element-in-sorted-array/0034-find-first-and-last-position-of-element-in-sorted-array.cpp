class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);

        // Target not found
        if (it1 == nums.end() || *it1 != target)
            return {-1, -1};

        auto it2 = upper_bound(nums.begin(), nums.end(), target);

        int first = it1 - nums.begin();
        int last = (it2 - nums.begin()) - 1;

        return {first, last};
    }
};