class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>freq;

        for(int x:nums){
            freq[x]++;
        }
        int ans=1;

        if(freq.count(1)){
            ans=max(ans,(freq[1]%2==0)?freq[1]-1:freq[1]);
        }

        for(auto &[x,cnt]:freq){
            if(x==1) continue;

            long long cur=x;

            int len=1;

            while(freq[cur]>=2){
                if(cur*cur >1e9 || !freq.count(cur*cur)) break;

                len+=2;
                cur=cur*cur;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};