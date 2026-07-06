class Solution {
public:
    string minWindow(string s, string t) {

        int hash[256] = {0};

        for (char c : t)
            hash[c]++;

        int i = 0, j = 0;
        int cnt = 0;

        int start = -1;
        int minLen = INT_MAX;

        while (j < s.size()) {

            // Include current character
            if (hash[s[j]] > 0)
                cnt++;

            hash[s[j]]--;
            j++;

            // Shrink window
            while (cnt == t.size()) {

                if (j - i < minLen) {
                    minLen = j - i;
                    start = i;
                }

                hash[s[i]]++;

                if (hash[s[i]] > 0)
                    cnt--;

                i++;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};