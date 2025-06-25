class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        

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