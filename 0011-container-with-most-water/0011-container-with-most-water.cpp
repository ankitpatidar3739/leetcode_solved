class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        int i=0;
        int j=n-1;
        int maxArea=0;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int area=w*h;
            maxArea=max(area,maxArea);

            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
};