class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26]={0};
        if (s.size() != t.size())
        return false;

        for(char c:s){
            hash[c-'a']++;
        }

        for(char d:t){
            if(hash[d-'a']>0){
                hash[d-'a']--;
            }else{
                return false;
            }
        }
        return true;
    }
};