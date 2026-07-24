class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        freq={}
        l=0
        r=0
        ans=0
        for r in range (len(s)):
            while s[r] in freq:
                del freq[s[l]]
                l+=1
            
            freq[s[r]]=1

            ans=max(ans,r-l+1)
        
        return ans