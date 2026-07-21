class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash + 256, -1);
        int len=0,maxi=0;
        int i=0,j=0;
        if(s.length()==0) return 0;
        while(j<s.length()){
            if(hash[s[j]]!=-1){
                if(hash[s[j]]>=i){
                   i=hash[s[j]]+1;
                }
            }
            len=j-i+1;
            maxi=max(maxi,len);
            hash[s[j]]=j;
            j++;
        }
        return maxi;
    }
};