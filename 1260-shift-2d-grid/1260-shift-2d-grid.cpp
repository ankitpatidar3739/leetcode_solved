class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int l=n*m;
        k%=l;
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int oidx=i*n+j;
                int idx=(oidx+k)%l;
               

                ans[idx/n][idx%n]=grid[i][j];
            }
        }
        return ans;
    }
};