class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>pre(n);
        pre[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=min(nums[i],pre[i+1]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int ans=maxi-pre[i];
            if(ans<=k) return i;
        }
        return -1;
    }
};