class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;
        string s=to_string(n);

        for(char c:s){
            if(c-'0' !=0){
                sum+=c-'0';
                num=num*10+(c-'0');
            }
        }
        return sum*num;
    }
};