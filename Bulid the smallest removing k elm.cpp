/*
The idea is based on the fact that a character among first (n+1) characters must be there in resultant number. 
So we pick the smallest of first (n+1) digits and put it in result, and recur for the remaining characters.
Initialize result as empty string
     res = ""
buildLowestNumber(str, n, res)
1) If n == 0, then there is nothing to remove.
   Append the whole 'str' to 'res' and return

2) Let 'len' be length of 'str'. If 'len' is smaller or equal 
   to n, then everything can be removed
   Append nothing to 'res' and return

3) Find the smallest character among first (n+1) characters
   of 'str'.  Let the index of smallest character be minIndex.
   Append 'str[minIndex]' to 'res' and recur for substring after
   minIndex and for n = n-minIndex
 
Return 0 if k >=n. and return num if k=0.
Create a stack and iterate through num string and push the value at that position if it is greater than the top element of the stack.
Iterate through the num string and if the integer value at that position is less than the top of the stack we will pop the stack and decrement k until we reach the condition where the top of the stack is less than the value we are looking at(while k>0) (by this we are making sure that most significant positions of the result are filled with minimum values).
If the k is still greater than 0 we will pop stack until k becomes 0.
Append the elements in the stack to the result string.
Delete leading zeroes from the result string.   */

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

string buildLowestNumber(string num, int k) 
{
    int n = num.size();
    stack<char> mystack;
    //Store the final string in stack
    for(char c: num)
    {
        while(!mystack.empty() && k>0 && mystack.top()>c)
        {   mystack.pop();      k-=1;   }
        
        if(!mystack.empty() || c!='0')
            mystack.push(c);
    }
    
    //remove the largest values from the top of the stack
    while(!mystack.empty() && k--)
        mystack.pop();
    if(mystack.empty())
        return "0";
    
    //retrieve the number from stack into a string (reusing num)
    while(!mystack.empty())
    {
        num[n-1] = mystack.top();
        mystack.pop();
        n-=1;
    }
    return num.substr(n);
}