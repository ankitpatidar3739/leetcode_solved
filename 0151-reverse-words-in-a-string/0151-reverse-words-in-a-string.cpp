class Solution {
public:
    string reverseWords(string s) {

        string ans = "";
        int j = s.size() - 1;

        while (j >= 0) {

            // Skip spaces
            while (j >= 0 && s[j] == ' ')
                j--;

            if (j < 0)
                break;

            int end = j;

            // Find the beginning of the word
            while (j >= 0 && s[j] != ' ')
                j--;

            int start = j + 1;

            // Copy the whole word
            ans += s.substr(start, end - start + 1);

            // Add one space if more words remain
            while (j >= 0 && s[j] == ' ')
                j--;

            if (j >= 0)
                ans += ' ';
        }

        return ans;
    }
};