class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            int freq[10]={0};
            
            for(int j=0;j<9;j++){

                if(board[i][j]=='.') continue;

                int digit=board[i][j]-'0';

                if(freq[digit]){
                    return false;
                }else{
                    freq[digit]++;
                }
            }
        }
        for(int j=0;j<9;j++){
            int freq[10]={0};
            
            for(int i=0;i<9;i++){

                if(board[i][j]=='.') continue;

                int digit=board[i][j]-'0';

                if(freq[digit]){
                    return false;
                }else{
                    freq[digit]++;
                }
            }
        }

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){

                int freq[10]={0};

                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        char ch=board[i+k][j+l];

                        if(ch=='.') continue;

                        int digit=ch-'0';

                        if(freq[digit]){
                            return false;
                        }freq[digit]++;
                    }
                }
            }
        }
        return true;
    }
};