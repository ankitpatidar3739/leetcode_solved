class Solution {
    bool func(int n,int k,vector<int>& arr){
        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;

        if(arr[0]<=k) prev[arr[0]]=true;

        for(int idx=1;idx<n;idx++){
            for(int target=1;target<=k;target++){
                bool nottake=prev[target];
                bool take=false;
                if(arr[idx]<=target) take=prev[target-arr[idx]];
                curr[target]=take|nottake;
            }
            prev=curr;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total%2!=0) return false;
        int target=total/2;

        return func(n,target,nums);
    }
};