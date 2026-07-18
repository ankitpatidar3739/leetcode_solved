class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};