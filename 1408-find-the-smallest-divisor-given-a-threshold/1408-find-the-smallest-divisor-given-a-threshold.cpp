class Solution {
    int func(vector<int>& nums,int d){
        int val=0;
        for(int i=0;i<nums.size();i++){
            val+=ceil((double)(nums[i])/(double)(d));
        }
        return val;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int val=func(nums,mid);
            if(val<=threshold){
                ans=mid;
                high=mid-1;
                
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};