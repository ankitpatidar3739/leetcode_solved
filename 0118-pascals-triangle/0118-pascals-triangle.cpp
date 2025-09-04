class Solution {
    vector<int>generaterow(int numRows){
        long long ans=1;
        vector<int>ansrow;
        ansrow.push_back(1);
        for(int i=1;i<numRows;i++){
            ans=ans*(numRows-i);
            ans=ans/i;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ansarr;
        for(int i=1;i<=numRows;i++){
            ansarr.push_back(generaterow(i));
        }
        return ansarr;
    }
};