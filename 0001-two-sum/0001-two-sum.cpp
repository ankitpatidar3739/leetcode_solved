class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int>st;

        for(int x:nums){
            st.insert(x);
        }

        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];

            auto it=find(nums.begin()+i+1,nums.end(),diff);
            if(it!=nums.end()){
                return {i,static_cast<int>(it-nums.begin())};
            }
        }
        return {};
    }
};