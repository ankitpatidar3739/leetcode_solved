class Solution {
public:
    
    int myAtoi(string s) {
       
        int i=0;
        int n=s.size();
        long long num=0;

        while(i<s.size() && s[i]==' '){
            i++;
        }
         int sign=1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-')
                sign = -1;

            i++;
        }
        while(i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // 4. Check overflow before adding digit
            if(num > (INT_MAX - digit) / 10) {
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            num = num * 10 + digit;

            i++;
        }
        return sign*num;
    }
};