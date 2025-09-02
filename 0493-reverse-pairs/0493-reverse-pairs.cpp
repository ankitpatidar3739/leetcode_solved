class Solution {
    void merge(int low,int mid,int high,vector<int>& nums){
        vector<int>temp;
        int left=low;
        int right=mid+1;

        while(left<=mid && right<=high){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    int count(int low,int mid,int high,vector<int>& nums){
        int right=mid+1;
        int cnt=0;

        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)nums[i]>2*(long long)nums[right]){
                right++;
            }
            cnt+=(right-(mid+1));
        }
        return cnt;
    }
    int mergesort(int low,int high,vector<int>& nums){
        int cnt=0;
        if(low>=high) return cnt;
        int mid=(low+high)/2;
        cnt+=mergesort(low,mid,nums);
        cnt+=mergesort(mid+1,high,nums);
        cnt+=count(low,mid,high,nums);
        merge(low,mid,high,nums);

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
       
    }
};