"""
303. Range Sum Query - Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
"""

class NumArray:
    
    sumList = [0]
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        size = len(nums)
        self.sumList = [0 for i in range(size)]

        if size == 0:
            return
        else:
            self.sumList[0] = nums[0]
    
        for i in range(1,size):
            self.sumList[i] = self.sumList[i-1] + nums[i]

        
        

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if i ==0:
            return self.sumList[j]
        else:
            return self.sumList[j]-self.sumList[i-1]
        


# Your NumArray object will be instantiated and called as such:
nums = [-2, 0, 3, -5, 2, -1]
obj = NumArray(nums)
print(obj.sumRange(0,5))