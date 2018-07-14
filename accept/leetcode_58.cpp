/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5*/
#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        int i=size -1;
        for(;i>=0;i--){
            if(s[i]==' '&&i==size-1){
                size--;
                continue;
            }else if(s[i]==' '){
                break;
            }
        }
        if(i == -1){
            return size;
        }else{
            return size-1-i;
        }
    }
};

int main()
{
    Solution s;
    cout<<s.lengthOfLastWord("Hello worlds ");
    return 0;
}