class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(128,0);

        for(char c:s){
            freq[c]++;
        }
        int cnt=0;
        bool odd=false;
        for(int x:freq){
            if(x%2==0){
                cnt+=x;
            }else{
                cnt+=x-1;
                odd=true;
            }
        }
        if(odd) cnt++;
        return cnt;
    }
};