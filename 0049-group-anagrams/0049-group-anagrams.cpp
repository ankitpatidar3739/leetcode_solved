class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>>mpp;

        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mpp[s].push_back(strs[i]);
        }

        vector<vector<string>>ans(mpp.size());

        int index=0;
        for(auto it:mpp){
            auto temp=it.second;

            for(auto it:temp){
                ans[index].push_back(it);
            }
            index++;

        }
        return ans;

    }
};