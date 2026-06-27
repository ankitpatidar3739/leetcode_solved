class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if (nums.empty())
    return {};
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+1==nums[i+1]){
                int first=nums[i];
                int last=nums[i];
                while(i+1<nums.size() && nums[i]+1==nums[i+1]){
                    last=nums[i+1];
                    i++;
                }
                ans.push_back(to_string(first)+"->"+to_string(last));
            }else{
                ans.push_back(to_string(nums[i]));
            }
        }
        if (nums.size() == 1 || nums.back() != nums[nums.size()-2] + 1)
        ans.push_back(to_string(nums.back()));
        return ans;
    }
};