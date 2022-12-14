/*
Let m be the value = n/26 and add the whole alphabetic string to the answer m times.
Let r be the value = n%26 and now we need to find the string 
for the length of r and add to the end of the string.
When N is even Use N/2 characters from the beginning of a-z and N/2 characters from the ending of a-z.
When N is odd 
 Case 1: If the sum of digits of N is even, 
 Select (N+1)/2 characters from the beginning of a-z and (N-1)/2 characters from the ending of a-z.
Case 2: If the sum of digits of N is odd,
 Select (N-1)/2 characters from the beginning of a-z and (N+1)/2 characters from the ending of a-z.
 Let m be the value = n/26 and add the whole alphabetic string to the answer m times.
Let r be the value = n%26 and now we need to find the string for the length of r and
 add to the end of the string.
When N is even Use N/2 characters from the beginning of a-z and N/2 characters from the ending of a-z.
When N is odd 
 Case 1: If the sum of digits of N is even, 
 Select (N+1)/2 characters from the beginning of a-z and (N-1)/2 characters from the ending of a-z.
Case 2: If the sum of digits of N is odd,
 Select (N-1)/2 characters from the beginning of a-z and (N+1)/2 characters from the ending of a-z.*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string BalancedString(int N) {
        string ans = "", full = "";
        for (char ch = 'a'; ch <= 'z'; ch++) full += ch;
        int a = N / 26, b = N % 26, i;
        while (a--) // appending a-z to answer as many times as possible
            ans += full;
        // when N is even
        if (N % 2 == 0) {
            for (i = 0; i < b / 2; i++) ans += (char)('a' + i);
            for (i = 26 - b / 2; i < 26; i++) ans += (char)('a' + i);
        }
        // when N is odd
        else {
            int SumOfdigits = 0, temp = N;
            // calculating sum of digits of N
            while (temp) {
                SumOfdigits += temp % 10;
                temp /= 10;
            }
            // when sum of digits is even
            if (SumOfdigits % 2 == 0) {
                for (i = 0; i < (b + 1) / 2; i++) ans += (char)('a' + i);
                for (i = 26 - b / 2; i < 26; i++) ans += (char)('a' + i);
            }
            // when sum of digits is odd
            else {
                for (i = 0; i < b / 2; i++) ans += (char)('a' + i);
                for (i = 26 - (b + 1) / 2; i < 26; i++) ans += (char)('a' + i);
            }
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

