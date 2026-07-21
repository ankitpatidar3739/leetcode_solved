class Solution {
public:
    int jump(vector<int>& arr) {
        long long jumps=0;
        int l=0;
        int r=0;
        int n=arr.size();

        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+arr[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
            
        }
        return jumps;
    }
};