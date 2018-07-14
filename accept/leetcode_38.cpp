/* The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.*/
#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    string parseStr(string str){
        int count =1;
        string result = "";
        for(int i=0;i<str.length()-1;i++){
            if(str[i] == str[i+1]){
                count ++;
                continue;
            }
            string countStr = to_string(count);
            result += countStr;
            result += str[i];
            count =1;
        }
        string countStr = to_string(count);
        result += countStr;
        result += str[str.length()-1];
        return result;
    }

    string countAndSay(int n) {
        string str = "11";
        if(n==1)return "1";
        if(n==2)return "11";
        while(n-2){
            str = parseStr(str);
            n--;
        }
        return str;

    }
    
};

int main()
{
    Solution s;
    cout<< s.countAndSay(1)<<endl;
    cout<< s.countAndSay(2)<<endl;
    cout<< s.countAndSay(3)<<endl;
    cout<< s.countAndSay(4)<<endl;
    cout<< s.countAndSay(5)<<endl;
    cout<< s.countAndSay(6)<<endl;
    cout<< s.countAndSay(7)<<endl;

    return 0;
}