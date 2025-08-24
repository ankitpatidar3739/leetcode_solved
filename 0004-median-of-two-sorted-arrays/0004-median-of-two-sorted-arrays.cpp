class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums1.size()+nums2.size();
        int idx1=n/2;
        int idx2=idx1-1;
        int cnt=0;
        int idx1el=-1,idx2el=-1;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(cnt==idx1) idx1el=nums1[i];
                if(cnt==idx2) idx2el=nums1[i];
                cnt++;
                i++;
            }else{
                if(cnt==idx1) idx1el=nums2[j];
                if(cnt==idx2) idx2el=nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<nums1.size()){
                if(cnt==idx1) idx1el=nums1[i];
                if(cnt==idx2) idx2el=nums1[i];
                cnt++;
                i++;
        }
        while(j<nums2.size()){
                if(cnt==idx1) idx1el=nums2[j];
                if(cnt==idx2) idx2el=nums2[j];
                cnt++;
                j++;
        }
        if(n%2==1){
            return idx1el;
        }
        return (double)((double)(idx1el+idx2el))/2.0;
        
    }
};