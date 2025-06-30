class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1,          std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());

        std::vector<int> distinct_in_nums1;
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                distinct_in_nums1.push_back(num);
            }
        }

        std::vector<int> distinct_in_nums2;
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                distinct_in_nums2.push_back(num);
            }
        }
        
        std::vector<std::vector<int>> result;
        result.push_back(distinct_in_nums1);
        result.push_back(distinct_in_nums2);

        return result;
    }
};