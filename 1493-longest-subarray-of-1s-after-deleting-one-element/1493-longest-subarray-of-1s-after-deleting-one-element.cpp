class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int cnt=0;
        int len=0;

        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                cnt++;
            }
            while(cnt>1){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
            len=max(len,r-l);
        }
        return len;
    }
};