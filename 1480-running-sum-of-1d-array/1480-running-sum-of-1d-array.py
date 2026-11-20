class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        # l=[]
        # l.append(nums[0])
        for i in range(1,len(nums)):
            nums[i]=nums[i]+nums[i-1]
        
        return nums