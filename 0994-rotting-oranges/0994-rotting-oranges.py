class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows=len(grid)
        cols=len(grid[0])

        q=deque()
        fresh=0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j]==2:
                    q.append((i,j))
                elif grid[i][j]==1:
                    fresh+=1
        
        min=0

        dr=[-1,0,1,0]
        dc=[0,-1,0,1]

        while q and fresh:
            for _ in range (len(q)):
                r,c=q.popleft()

                for i in range(4):
                    nr=r+dr[i]
                    nc=c+dc[i]

                    if(0<=nr<rows and 0<=nc<cols and grid[nr][nc]==1):
                        grid[nr][nc]=2
                        fresh-=1
                        q.append((nr,nc))
            
            min+=1
        
        return min if fresh==0 else -1