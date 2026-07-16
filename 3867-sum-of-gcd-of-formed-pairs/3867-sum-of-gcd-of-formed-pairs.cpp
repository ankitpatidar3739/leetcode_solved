class Solution {
public:
    int fgcd(int a,int b){
        if(b==0) return a;

        return fgcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        vector<int>prefixGcd(n);
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            prefixGcd[i]=fgcd(nums[i],maxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0;
        int j=n-1;

        long long sum=0;
        while(i<j){
            sum+=fgcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};