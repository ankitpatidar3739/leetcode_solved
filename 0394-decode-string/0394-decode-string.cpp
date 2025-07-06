class Solution {
public:
    string decodeString(string s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) {
                res += s[i++];
            } else {
                int count = 0;
                while (i < s.length() && isdigit(s[i])) {
                    count = count * 10 + (s[i++] - '0');
                }
                
                i++; // skip '['
                string decoded = decodeString(s, i);
                i++; // skip ']'
                
                while (count-- > 0) {
                    res += decoded;
                }
            }
        }
        
        return res;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};