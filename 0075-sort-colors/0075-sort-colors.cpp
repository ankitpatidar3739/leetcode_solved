class Solution {
public:
    void sortColors(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());

        vector<int>arr(maxi+1,0);

        for(int x:nums){
            arr[x]++;
        }
        int idx=0;
        for(int i=0;i<=maxi;i++){
            while(arr[i]--){
                nums[idx++]=i;
            }
        }
    }
};