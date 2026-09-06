class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int n=interval.size();
        vector<vector<int>>res;
        int i=0;

        while(i<n && interval[i][1]<newInterval[0]){
            res.push_back(interval[i]);
            i++;
        }
        while(i<n && interval[i][0]<=newInterval[1]){
            newInterval[0]=min(interval[i][0],newInterval[0]);
            newInterval[1]=max(interval[i][1],newInterval[1]);
            i++;
        }
         res.push_back(newInterval);
        
        while(i<n){
            res.push_back(interval[i]);
            i++;
        }
       
        return res;
    }
};