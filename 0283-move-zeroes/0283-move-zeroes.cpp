class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = i + 1;

       while(j<n){
        if(arr[i]==0 && arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }else if(arr[i]==0 && arr[j]==0){
            j++;
        }else{
            i++;
            if(j<=i) j=i+1;
        }
       }
    }
};
