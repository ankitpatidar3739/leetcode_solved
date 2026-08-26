class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        int len=INT_MAX;
        string ans="";
        int cnt=0;
        
        for(int j=0;j<n;j++){
            if(s[j]=='1'){
                cnt++;
            }
            if(cnt==k){
                while(s[i]=='0') i++;

                int cur=j-i+1;
                if(cur<len || (cur==len && s.substr(i,cur)<ans)){
                    len=cur;
                    ans=s.substr(i,j-i+1);
                }
                cnt--;
                i++;
            }
        }
        return ans;
    }
};