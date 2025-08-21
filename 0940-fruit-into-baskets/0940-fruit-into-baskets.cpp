class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         int k=0,s=0, maxlen=0;unordered_map<int,int>mpp;
        while(k<fruits.size())
        {
            mpp[fruits[k]]=k;
            if(mpp.size()>2)
            {
               int minindex=fruits.size();
               for(auto &it:mpp)minindex=min(minindex,it.second);
               s=minindex+1;
               mpp.erase(fruits[minindex]);
            }
            maxlen=max(maxlen,k-s+1);
            k++; 
        }
    return maxlen;
    }
};