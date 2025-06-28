class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r,l=0;
        int zeroes=0;
        int maxlength=0;

        while(r<nums.size()){
            if(nums[r]==0){
                zeroes++;
            }
            if(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            if(zeroes<=k){
                maxlength=max(r-l+1,maxlength);
            }
            r++;
        }
        return maxlength;
    }
};