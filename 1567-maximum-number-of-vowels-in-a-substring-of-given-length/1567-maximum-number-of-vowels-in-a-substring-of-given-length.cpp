class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0;
        int maxcount = 0;
        int l=0,r=0;

        while(r<n){
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u'){
                count++;
            }
            if(r-l+1>k){
                if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
                    count--;
                    l++;
                
            }
            maxcount=max(count,maxcount);
            r++;

        }
        return maxcount;
    }
};