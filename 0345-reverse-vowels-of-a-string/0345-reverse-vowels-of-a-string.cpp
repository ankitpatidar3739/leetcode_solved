class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            // Move i forward if s[i] is not a vowel
            if (!isVowel(s[i])) {
                i++;
            }
            // Move j backward if s[j] is not a vowel
            else if (!isVowel(s[j])) {
                j--;
            }
            // Both are vowels, so swap and move both
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }

    // Helper function to check for vowels
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
