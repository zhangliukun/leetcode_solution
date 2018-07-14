/*Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.*/
#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i=0,flag = 0;
        int temp = digits[size-1]+1;
        if(temp >=10){
            flag =1;
            digits[size-1]= temp-10;
        }else{
            digits[size-1]++;
            return digits;
        }
        for(i=size-2;i>=0;i--){
            if(flag == 1){
                temp =digits[i]+1;
                flag = 0;
            }
            if(temp>=10){
                flag =1;
                digits[i]= temp-10;
            }else{
                digits[i] += 1;
                break;
            }
        }
        if(flag ==1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

int main()
{
    Solution s;

    return 0;
}