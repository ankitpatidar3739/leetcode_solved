class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string result="";

        while(i<word1.size() && j<word2.size()){
            result=result+word1[i];
            i=i+1;
            result=result+word2[j];
            j=j+1;
        }
        while(i<word1.size()){
            result=result+word1[i];
            i=i+1;
        }
        while(j<word2.size()){
            result=result+word2[j];
            j=j+1;
         }
         return result;
    }
};