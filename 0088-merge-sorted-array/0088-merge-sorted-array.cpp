class Solution {
    // private:
    // void swapp(vector<int>& nums1, vector<int>& nums2, int idx1,int idx2){
    //     if(nums1[idx1]>nums2[idx2]){
    //         swap(nums1[idx1],nums2[idx2]);
    //     }
    // }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int length=n+m;
        // int gap=(length/2)+(length%2);

        // while(gap>0){
        //     int left=0;
        //     int right=left+gap;

        //     while(right<length){

        //         if(left<n && right>=n){
        //             swapp(nums1,nums2,left,right-n);
        //         }else if(left>=n){
        //             swapp(nums1,nums2,left-n,right-n);
        //         }else{
        //             swapp(nums1,nums2,left,right);
        //         }
        //         left++;
        //         right++;
        //     }
        //     if(gap==1) break;
        //     gap=(gap/2)+(gap%2);
        // }

        // int left=n-1;
        // int right=0;

        // while(left>=0 && right<m){
        //     if(arr1[left]>arr2[right]){
        //         swap(arr1[left],arr2[right]);
        //         left--;
        //         right++;
        //     }else{
        //         break;
        //     }
        // }
        // sort(arr1.begin(),arr1.end());
        // sort(arr2.begin(),arr2.end());

        int totalLength = m + n;
        int gap = (totalLength + 1) / 2;

        // Copy nums2 into nums1's empty space
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        while (gap > 0) {
            int i = 0;
            int j = gap;

            while (j < totalLength) {
                if (nums1[i] > nums1[j]) {
                    swap(nums1[i], nums1[j]);
                }
                i++;
                j++;
            }

            if (gap == 1) break;
            gap = (gap + 1) / 2;
        }
    }
};