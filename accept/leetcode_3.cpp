/* Given a string, find the length of the longest substring without repeating characters.
    Examples:
    Given "abcabcbb", the answer is "abc", which the length is 3.
    Given "bbbbb", the answer is "b", with the length of 1.
    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }

    int lengthOfLongestSubstring(string s) {
        map<char,int> charmap;
        int result =0;
        for(int i=0,j=0;j<s.length();j++)
        {
            map<char,int>::iterator iter;
            iter = charmap.find(s[j]);
            if(iter == charmap.end())
            {
                charmap.insert(make_pair(s[j],j));
            }
            else
            {
                i = max(iter->second +1,i);
                charmap[s[j]] = j;
                
            }
            result = max(result,j-i+1);
        }

        printf("%d\n",result);
        return result;
    }
};

int main()
{
    Solution s;
    string str = "bbbbb";
    s.lengthOfLongestSubstring(str);
    return 0;
}