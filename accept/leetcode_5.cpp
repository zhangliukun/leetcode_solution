/* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb" */
#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        
        vector<vector<int> > dp(s.length(),vector<int>(s2.length(),0));

        int max = INT_MIN;
        int end = 0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s2.length();j++){
                if(s[i] == s2[j]){
                    if(i==0||j==0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] += dp[i-1][j-1]+1;
                    }
                    if(dp[i][j]>max){
                        max = dp[i][j];
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(end-max+1,max);

    }
    bool checkIsP(string s){
        int n = s.length()/2;
        int size = s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=s[size-i-1]){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.longestPalindrome("abcdasdfghjkldcba");
    return 0;
}