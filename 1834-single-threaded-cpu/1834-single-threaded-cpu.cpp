class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>>sortedtasks;

        for(int i=0;i<n;i++){
            sortedtasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(begin(sortedtasks),end(sortedtasks));

        long long curr=0;
        int idx=0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>>pq;
        vector<int>result;
        while(idx<n || !pq.empty()){
            if(pq.empty()){
                curr = max(curr, (long long)sortedtasks[idx][0]);
            }

            while(idx<n && sortedtasks[idx][0]<=curr){
                pq.push({sortedtasks[idx][1],sortedtasks[idx][2]});
                idx++;
            }

            pair<int,int> curr_task=pq.top();
            pq.pop();

            curr+=curr_task.first;
            result.push_back(curr_task.second);
        }
        return result;
    }
};