/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include <stack>
#include <limits>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '('||s[i] == '{'||s[i] == '[')
            {
                st.push(s[i]);
            }else {
                if(st.empty())return false;
                switch(s[i])
                {
                    case ')':if(st.top()!='('){return false;}else{st.pop();}break;
                    case '}':if(st.top()!='{'){return false;}else{st.pop();}break;
                    case ']':if(st.top()!='['){return false;}else{st.pop();}break;
                }
            }
        }
        if(!st.empty())return false;
        return true;
    }
    
};

int main()
{
    Solution s;
    cout<<s.isValid("]")<<endl;
    cout<<s.isValid("([)]");
    

    return 0;
}