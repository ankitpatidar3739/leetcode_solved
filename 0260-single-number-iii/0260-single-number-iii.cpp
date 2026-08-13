class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;

        for(int x:nums){
            ans^=x;
        }

        unsigned int u = (unsigned int)ans;
        unsigned int bit = u & -u;

        int a=0,b=0;

        for(int x:nums){
            if((unsigned int)x&bit){
                a^=x;
            }else{
                b^=x;
            }
        }
        return {a,b};
    }
};