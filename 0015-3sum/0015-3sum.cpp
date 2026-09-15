class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int i=0;
        int j=n-1;
        
        for(i=0;i<nums.size()-2;i++){
            int k=i+1;
            j=n-1;
            while( k<j){
                
            if(nums[i]+nums[j]+nums[k]==0){
                st.insert({nums[i],nums[k],nums[j]});
                k++;
            }else if(nums[i]+nums[j]+nums[k]<0){
                k++;
            }else{
                j--;
            }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};