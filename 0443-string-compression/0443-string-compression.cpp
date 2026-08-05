class Solution {
public:
    int compress(vector<char>& chars) {

        int pos=0;
        int count=1;
        int n=chars.size();

        for(int i=1;i<=chars.size();i++){
            if(i<n && chars[i]==chars[i-1]){
                count++;
            }else{
                chars[pos++]=chars[i-1];

                if(count>1){
                    string add=to_string(count);
                    for(char c:add){
                        chars[pos++]=c;
                    }
                }
                count=1;
            }
        }
        return pos;
    }
};