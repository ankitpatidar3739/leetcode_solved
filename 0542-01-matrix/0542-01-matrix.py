class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows=len(mat)
        cols=len(mat[0])

        q=deque()

        for i in range(rows):
            for j in range(cols):
                if mat[i][j]==0:
                    q.append((i,j))
                else:
                    mat[i][j]=-1
        
        dr=[-1,0,1,0]
        dc=[0,-1,0,1]

        while q:
            r,c=q.popleft()

            for i in range(4):
                nr=r+dr[i]
                nc=c+dc[i]

                if(0<=nr<rows and 0<=nc<cols and mat[nr][nc]==-1):
                    mat[nr][nc]=mat[r][c]+1
                    q.append((nr,nc))
        
        return mat