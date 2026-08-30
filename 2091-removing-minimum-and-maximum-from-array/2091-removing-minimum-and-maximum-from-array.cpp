class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=INT_MIN;
        int maxIdx=0;
        int mini=INT_MAX;
        int minIdx=0;
        int n=nums.size();

        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxIdx=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minIdx=i;
            }
        }

        int op1=max(maxIdx,minIdx)+1;
        int op2=n-min(maxIdx,minIdx);
        int op3=(maxIdx+1)+(n-minIdx);
        int op4=(minIdx+1)+(n-maxIdx);

        return min({op1,op2,op3,op4});

        
    }
};