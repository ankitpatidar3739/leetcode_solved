class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int n=costs.size();

        priority_queue<int,vector<int>,greater<int>>pq1,pq2;

        int i=0;
        int j=n-1;
        int hired=0;
        long long ans=0;

        while(hired<k){

            while(pq1.size()<c && i<=j){
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size()<c && j>=i){
                pq2.push(costs[j]);
                j--;
            }

            int min1=pq1.size()>0?pq1.top():INT_MAX;
            int min2=pq2.size()>0?pq2.top():INT_MAX;

            if(min1<=min2){
                ans+=min1;
                pq1.pop();
            }else{
                ans+=min2;
                pq2.pop();
            }
            hired++;
        }
        return ans;
    }
};