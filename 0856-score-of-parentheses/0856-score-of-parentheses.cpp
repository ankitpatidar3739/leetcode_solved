class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                st.pop();

                if (s[i-1] == '(') {
                    cnt += (1 << st.size());
                }
            }
        }
        return cnt;
    }
};