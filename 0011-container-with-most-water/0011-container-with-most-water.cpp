class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int area=0;
        int maxi=INT_MIN;
        while(l<r){
            area=(min(height[l],height[r]))*(r-l);
            maxi=max(area,maxi);
            if(height[l]<=height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxi;
    }
};