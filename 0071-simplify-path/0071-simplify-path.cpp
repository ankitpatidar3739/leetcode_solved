class Solution {
public:
    string simplifyPath(string path) {
       stringstream ss(path);
       string token;
       vector<string>st;

       while(getline(ss,token,'/')){
        if(token.empty() || token=="."){
            continue;
        }else if(token==".."){
            if(!st.empty()) st.pop_back();
        }else{
            st.push_back(token);
        }
       }
       string ans="";

       for(string &dir:st){
        ans+="/"+dir;
       }
       if(ans.empty()) return "/";

       return ans;
    }
};