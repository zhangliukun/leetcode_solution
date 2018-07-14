'''
zigzag conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
'''
class Solution:
    
    '''
    第一种方法就是从字符串s的头按照行开始遍历，依次对rows列表的行进行操作。时间复杂度O(n)，其中n==len(s),空间复杂度为O(n)
    '''
    def convert(self, s, numRows):
        
        length = len(s);
        rows = ['' for i in range(min(length,numRows))];
        curRow = 0;

        if numRows == 1:
            return s;
        

        goDown = False;
        for c in s:
            rows[curRow] += c
            if(curRow ==0 or curRow == numRows -1):
                goDown = ~goDown
            curRow += 1 if goDown else -1
        
        ret =''
        for str in rows:
            ret += str

        return ret
    
    '''
    第二种方法是按照列开始访问，因为在第一行和最后一行之间是没有插入元素的，间距是一定的，然后中间的行之间有插入元素，间距也有规律。
    '''
    def convert2(self,s,numRows):
        if numRows == 1:
            return s
        ret = ''
        n = len(s)
        cycleLen = 2 * numRows -2

        for i in range(numRows):
            j = 0
            while j+i<n:
                ret += s[j+i]
                if i!=0 and i!=numRows-1 and j+cycleLen-i<n:
                    ret += s[j+cycleLen-i]
                j+=cycleLen
        
        return ret

test = Solution()
print(test.convert("sdfassdff",3))
print(test.convert2("sdfassdff",3))
        