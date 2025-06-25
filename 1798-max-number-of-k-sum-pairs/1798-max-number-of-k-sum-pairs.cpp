class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // int i=0;
        // int j=nums.size()-1;
        // int count=0;

        // sort(nums.begin(),nums.end());

        // while(i<j){
        //     int sum=nums[i]+nums[j];
        //     if(sum==k){
        //         count++;
        //         i++;
        //         j--;
        //     }else if(sum<k){
        //         i++;
        //     }else{
        //         j--;
        //     }
        // }
        // return count;

        unordered_map<int,int>freq;
        int count=0;

        for(int num:nums){
            int remains=k-num;
            if(freq[remains]>0){
                count++;
                freq[remains]--;
            }else{
                freq[num]++;
            }
        }
        return count;
    }
};