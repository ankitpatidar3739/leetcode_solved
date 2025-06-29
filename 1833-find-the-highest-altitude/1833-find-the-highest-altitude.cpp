class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefix=0;
        int altitude=0;

        for(int i=0;i<gain.size();i++){
            prefix+=gain[i];
            altitude=max(altitude,prefix);
        }
        return altitude;
    }
};