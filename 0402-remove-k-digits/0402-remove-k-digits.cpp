class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;  // Use as stack

        for (int i = 0; i < num.size(); ++i) {
            while (!st.empty() && k > 0 && st.back() > num[i]) {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        // If still some digits left to remove
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') i++;

        string res = st.substr(i);

        return res.empty() ? "0" : res;
    }
};