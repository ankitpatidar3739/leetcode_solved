class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapS[256] = {0}, mapT[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (mapS[s[i]] != mapT[t[i]]) return false;

            // store position+1 (so default 0 means "not seen yet")
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        return true;
    }
};