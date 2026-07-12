class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans=arr;
        
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());

        unordered_map<int,int>mpp;

        for(int i=0;i<ans.size();i++){
            mpp[ans[i]]=i+1;
        }

        vector<int>ans2;
        for(int x:arr){
            ans2.push_back(mpp[x]);
        }
        return ans2;
    }
};