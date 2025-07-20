class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int hash[256]={0};

        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int l=0,r=0,cnt=0;
        int sIndex=-1;
        int minLength=std::numeric_limits<int>::max(); 

            while(r<n){
                if(hash[s[r]]>0){
                    cnt++;
                } 
                hash[s[r]]--;
                
                while(cnt==m){
                    if(r-l+1 < minLength){
                        minLength=r-l+1;
                        sIndex=l;
                    }  
                    hash[s[l]]++;
                    
                    if(hash[s[l]]>0)cnt--;
                    l++;
                }
                r=r+1; 
            }
        return sIndex==-1 ? "":s.substr(sIndex,minLength);
    }
};