class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i] + (nums[i]==target);
        }
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int count=prefix[j+1]-prefix[i];
                int length=j-i+1;

                if(count>length/2) ans++;
            }
        }
        return ans;
    }
};