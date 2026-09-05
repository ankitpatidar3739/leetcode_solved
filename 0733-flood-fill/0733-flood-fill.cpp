class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int original = image[sr][sc];
        if(original == color) return image;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        image[sr][sc]=color;
        vis[sr][sc]=1;

        queue<pair<int,int>>q;
        q.push({sr,sc});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty() ){
            auto p=q.front();
            q.pop();

            int r=p.first;
            int c=p.second;

            for(int i=0;i<4;i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;

                if(0<=nr && nr<n && 0<=nc && nc<m && vis[nr][nc]==-1 && image[nr][nc]==original){
                    image[nr][nc]=color;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};