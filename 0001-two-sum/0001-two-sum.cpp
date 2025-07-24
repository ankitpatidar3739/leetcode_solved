class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        vector<int>ls;
        for(int i=0;i<nums.size();i++){
            int el=nums[i];
            int remaining=target-nums[i];
            if(mpp.find(remaining)!=mpp.end()){
                ls.push_back(mpp[remaining]);
                ls.push_back(i);
                
                // break;
            }
            mpp[el]=i;
        }
        return ls;

    }
};