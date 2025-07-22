class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(cnt==0) {
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el) {
                cnt++;
                }
            else {
                cnt--;
            }
        }
        return el;
    }
};