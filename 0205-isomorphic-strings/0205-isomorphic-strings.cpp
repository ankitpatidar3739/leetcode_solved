class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        // Two arrays (size 256 for ASCII) act as fast mapping tables.
        // 0 means unmapped.
        int s_to_t[256] = {0}; 
        int t_to_s[256] = {0}; 
        
        for (int i = 0; i < s.length(); ++i) {
            char char_s = s[i];
            char char_t = t[i];

            // 1. Check Forward Consistency (s -> t)
            // If char_s has a mapping:
            if (s_to_t[char_s] != 0) {
                // ...it MUST map to the current char_t.
                if (s_to_t[char_s] != char_t) {
                    return false; // Fails: 'o' -> 'a', then later 'o' -> 'r' ("foo" vs "bar")
                }
            } 
            // If char_s is NEW:
            else {
                // 2. Check Backward Uniqueness (t -> s)
                // Is the target char_t already taken by a DIFFERENT char_s?
                if (t_to_s[char_t] != 0) {
                    return false; // Fails: 'a' -> 'x', then later 'b' -> 'x' ("ab" vs "xx")
                }
                
                // Establish the consistent, new, and valid two-way map
                s_to_t[char_s] = char_t; 
                t_to_s[char_t] = char_s;
            }
        }
        
        return true;
    }
};