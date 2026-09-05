class Solution {
    typedef pair<int,int> P;
    private:
    void bfs(queue<P>q,vector<vector<int>> &vis,vector<vector<int>>& heights){
        int n=heights.size();
        int m=heights[0].size();

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && heights[nr][nc]>=heights[r][c]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> pvis(n,vector<int>(m,0));
        vector<vector<int>> avis(n,vector<int>(m,0));
        vector<vector<int>>ans;
        queue<pair<int,int>>p,a;

        for(int i=0;i<m;i++){
            pvis[0][i]=1;
            p.push({0,i});
        }
        for(int j=0;j<n;j++){
            pvis[j][0]=1;
            p.push({j,0});
        }
        for(int i=0;i<m;i++){
            avis[n-1][i]=1;
            a.push({n-1,i});
        }
        for(int j=0;j<n;j++){
            avis[j][m-1]=1;
            a.push({j,m-1});
        }
        bfs(p,pvis,heights);
        bfs(a,avis,heights);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pvis[i][j] && avis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};