class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        
        if(nums.empty()){
            return false;
        }

        int current_gcd=nums[0];

        for(int i=1;i<nums.size();i++){
            current_gcd=gcd(current_gcd,nums[i]);
            
            if(current_gcd==1){
                return true;
            }
        }
        return current_gcd==1;
    }
};