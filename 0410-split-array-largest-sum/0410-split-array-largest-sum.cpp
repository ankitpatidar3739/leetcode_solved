class Solution {
public:

    int cntsplit(vector<int>& arr,int num){
        int curr=1;
        long long total=0;
        for(int i=0;i<arr.size();i++){
            if(total+arr[i]<=num){
                total+=arr[i];
            }else{
                 curr++;
                 total=arr[i];
            }
        }
        return curr;
    }
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);

        while(low<=high){
            int mid=(low+high)/2;

            int split=cntsplit(arr,mid);

            if(split>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};