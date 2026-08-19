class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,int>mpp;
        for(int i=0;i<reservedSeats.size();i++){
            int row=reservedSeats[i][0];
            int seat=reservedSeats[i][1];

            if(mpp.find(row)==mpp.end()){
                mpp[row]=7;
            }
            if(seat==2 || seat==3){
                    mpp[row]&=3;
                }else if(seat==4 || seat==5){
                    mpp[row]&=1;
                } else if(seat==6 || seat==7){
                    mpp[row]&=4;
                }else if(seat==8 || seat==9){
                    mpp[row]&=6;
                }
        }  
        int ans=0; 
        for(auto it:mpp){
            int state=it.second;
            if(state==7 || state==5){
                ans+=2;
            }else if(state>0){
                ans+=1;
            }
        }
        return ans+=(n-mpp.size())*2;
    }
};