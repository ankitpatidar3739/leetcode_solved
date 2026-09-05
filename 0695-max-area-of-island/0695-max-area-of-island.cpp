class Solution {
    typedef pair<int,int>p;
    private:
        int bfs(int i,int j,vector<vector<int>>& grid){
            int n=grid.size();
            int m=grid[0].size();
            queue<pair<int,int>>q;
            q.push({i,j});
            grid[i][j]=0;
            int area=1;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};

            while(!q.empty()){
                auto p=q.front();
                int r=p.first;
                int c=p.second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nr=dr[i]+r;
                    int nc=dc[i]+c;

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        grid[nr][nc]=0;
                        area++;
                        q.push({nr,nc});
                    }
                }
            }
            return area;
        }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                    int area=bfs(i,j,grid);
                    maxi=max(maxi,area);
                }
            }
        }
        if(cnt==0) return 0;
        else return maxi;
    }
};