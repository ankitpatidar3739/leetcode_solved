class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int l=0;int r=0;
       vector<int> hash(256, -1);
        int n=s.size();

        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l ){
                l=hash[s[r]]+1;
            }

            hash[s[r]]=r;
            maxi=max(maxi,r-l+1);
            
            r++;
        }
    return maxi;
    }
};