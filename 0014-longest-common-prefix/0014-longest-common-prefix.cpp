class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans=0;
        string prex=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<strs[i].size() && j<prex.size() && strs[i][j]==prex[j]){
                j++;
            }
            prex=prex.substr(0,j);
            if(prex.empty()) break;
        }
        return prex;
    }
};