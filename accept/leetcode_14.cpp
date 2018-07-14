//Write a function to find the longest common prefix string amongst an array of strings.
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string>::iterator it;
        if(strs.empty())
        {
            return "";
        }
        for(int i=0;i<strs[0].length();i++)
        {
            string prefix = strs[0].substr(0,i+1);
            for(it = strs.begin()+1;it!=strs.end();it++)
            {
                if((*it).find(prefix)!=0)
                {
                    if(i==0)return "";
                    else{
                        return prefix.substr(0,prefix.length()-1);
                    }
                }
            }
        }
        return strs[0];
    }
    
};

int main()
{
    Solution s;
    vector<string> strs;
    strs.push_back("leetcode");
    strs.push_back("leet");
    strs.push_back("leeds");
    

    cout << s.longestCommonPrefix(strs);

    return 0;
}