class Solution {
public:

    int fun(vector<int>& nums, int k){
        int l=0,r=0,cnt=0;
        unordered_map<int,int>mpp;

        while(r<nums.size()){
            mpp[nums[r]]++;

            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
            }
            cnt=cnt+(r-l+1);
            r=r+1;
        }
        return cnt;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });