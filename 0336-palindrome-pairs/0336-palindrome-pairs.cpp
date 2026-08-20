class Solution {
public:
    bool ispal(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int>mpp;
        vector<vector<int>>ans;
        for(int i=0;i<words.size();i++){
            mpp[words[i]]=i;
        }

        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            for(int j=0;j<=word.size();j++){
                string left=word.substr(0,j);
                string right=word.substr(j);

                if(ispal(right,0,right.size()-1)){
                    string revleft=left;
                    reverse(revleft.begin(),revleft.end());

                    if(mpp.find(revleft)!=mpp.end()){
                        int idx=mpp[revleft];

                        if(idx!=i){
                            ans.push_back({i,idx});
                        }
                    }
                }
                if(j>0 && ispal(left, 0, left.size()-1)) {
                string revRight = right;
                reverse(revRight.begin(), revRight.end());

                if(mpp.find(revRight) != mpp.end()) {
                int idx = mpp[revRight];

                if(idx != i) {
                ans.push_back({idx, i});
                    }
                    }
                }
            }
        }
        return ans;

    }
};