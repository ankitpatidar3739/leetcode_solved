class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack=[]
        maxi=0
        n=len(heights)

        for i in range(n+1):
            while stack and (i==n or heights[stack[-1]]>=heights[i]):
                h=heights[stack.pop()]

                if stack:
                    width=i-stack[-1]-1
                else:
                    width=i
                
                maxi=max(maxi,h*width)
            stack.append(i)
        
        return maxi