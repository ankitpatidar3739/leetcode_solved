class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            result^=nums[i];
        }
        return result;
    }
};