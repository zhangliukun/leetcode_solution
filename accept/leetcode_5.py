"""
最长回文子串
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
"""

class Solution:
    
    # 动态规划解法
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        dp = [[False for i in range(n)]for i in range(n)]
        for i in range(n):
            dp[i][i] = True
            dp[i][i-1] = True
        ans = 1
        start = 0
        for l in range(2,n+1): #子串长度
            for i in range(n-l+1): #从0开始遍历
                j = i+l-1 #子串结尾处
                if dp[i+1][j-1] and s[i]==s[j]:
                    dp[i][j] = True
                    ans = l
                    start = i
        return s[start:start+ans]    

test = Solution()
print(test.longestPalindrome('ababa'))
