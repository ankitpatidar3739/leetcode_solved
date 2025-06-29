class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int suffix=0;
        for(int num:nums){
            suffix+=num;
        }
        int preffix=0;

        for(int i=0;i<nums.size();i++){
            suffix-=nums[i];

            if(preffix==suffix) return i;

            preffix+=nums[i];   
        }
        return -1;
    }
};