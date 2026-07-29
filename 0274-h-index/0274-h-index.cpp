class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        if(arr[0]==0 && arr.size()==1) return 0;
        // int maxi=1;

        for(int i=0;i<n;i++){
            if(arr[i]>=n-i){
                return n-i;
            }
        }
        return 0;
    }
};