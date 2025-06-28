class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int r,l=0;
        int zeroes=0;
        int maxlength=0;
        bool allOnes = true;

        while(r<nums.size()){
            if(nums[r]==0){
                zeroes++;
                allOnes = false;
            }
            if(zeroes>1){
                if(nums[l]==0) zeroes--;
                l++;
            }
                maxlength=max(r-l,maxlength);
            r++;
        }
         if (allOnes) {
            return nums.size() - 1;
        }

        return maxlength;
    }
};