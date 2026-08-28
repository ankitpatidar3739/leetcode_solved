class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int x:piles){
            pq.push(x);
        }
        int ans=0;
        while(k--){
            int val=pq.top();
            pq.pop();
            val=(val-floor(val/2));
            pq.push(val);
        }
        while(!pq.empty()){
            int val=pq.top();
            ans+=val;
            pq.pop();
        }
        return ans;
    }
};