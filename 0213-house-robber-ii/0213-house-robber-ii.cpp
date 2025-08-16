class Solution {
    private:
    int func(vector<int>&num){
        if (num.empty()) {
            return 0;
        }
        int prev=num[0];
        int prev2=0;

        for(int i=1;i<num.size();i++){
            int take=num[i];
            if(i>1) take+=prev2;

            int nottake=0+prev;

            int curr=max(take,nottake);
            prev2=prev;
            prev=curr; 
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
         if (n == 1) {
            return nums[0];
        }
        vector<int>temp1,temp2;

        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(func(temp1),func(temp2));
    }
};