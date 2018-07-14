"""
198. House Robber
给定一个数组，求不相邻的数字的总和最大的一个
Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
"""

class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        size = len(nums)
        if size == 1:
            return nums[0]
        elif size == 0:
            return 0

        money = [0 for i in range(size)]
        money[0] = nums[0]
        money[1] = nums[1]
        for i in range(2,size):
            money[i] = nums[i]+ max(money[i-1]-nums[i-1],money[i-2])

        print(max(money))
        

test = Solution()
test.rob([2,1,2,6,1,8,10,10])