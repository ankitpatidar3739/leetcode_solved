class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char c : tasks)
            freq[c - 'A']++;

        int mx = *max_element(freq.begin(), freq.end());

        int count = 0;
        for(int x : freq)
            if(x == mx)
                count++;

        int ans = (mx - 1) * (n + 1) + count;

        return max((int)tasks.size(), ans);
    }
};