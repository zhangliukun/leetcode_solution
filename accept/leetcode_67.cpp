/*Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".*/
#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        int i = a.length()-1;
        int j = b.length()-1;
        int flag=0;
        while(i>=0||j>=0||flag ==1){
            flag += i>=0?a[i--]-'0':0;
            flag += j>=0?b[j--]-'0':0;
            result += (char)(flag%2+'0');
            flag/=2;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.addBinary("11","101");
    return 0;
}