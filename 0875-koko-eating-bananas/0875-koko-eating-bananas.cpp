class Solution {

    bool helper(vector<int>& piles,int speed,int h){

        long long total=0;
        for(int i=0;i<piles.size();i++){
            total += (1LL * piles[i] + speed - 1) / speed;
        }
        if (total > h)
        return false;
        if(total<=h){
            return true;
        }
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int mx = *max_element(piles.begin(), piles.end());
        int high=mx;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(helper(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};