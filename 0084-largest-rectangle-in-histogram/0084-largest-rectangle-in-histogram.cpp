class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxi=0;
        stack<int>st;

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi,(nse-pse-1)*arr[element]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=arr.size();
            int element=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi,(nse-pse-1)*arr[element]);
        }
        return maxi;

    }
};