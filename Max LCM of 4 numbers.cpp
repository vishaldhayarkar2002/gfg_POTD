/*
The answer will always contain N and N-1 as consecutive numbers are co primes and
 their lcm will be the product of two numbers.
Now we need to find 2 numbers such that the lcm of four numbers is maximum.
We will first find out the lcm of N,N-1,N-2,N-3. Then we start iterating from N-2 
and check if the lcm of first 2 numbers is co prime with the given number. 
If it is then we include the number and multiply it.
Then we search for the last number when we find the gcd of that number and
the previous processed number if they are co primes then we include in the answer and break from the loop.
We choose the maximum answer from the lcm of last four numbers or the above processed number.
We do the same above process for N-1 and we return the max number from the above process of N and N-1.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long gcd(long long A, long long B) {
        if (B == 0) return A;
        return gcd(B, A % B);
    }
    long long lcm(int N){
        if (N == 4) return 12;
        long long a = N * (N - 1);
        long long b = a;
        b *= (N - 2) / gcd(b, N - 2);
        b *= (N - 3) / gcd(b, N - 3);
        long long c = a, f = 0;
        for (int i = N - 2; i >= 1; i--) {
            if (gcd(c, i) == 1) {
                a *= i;
                c *= i;
                f++;
            }
            if (f == 2) break;
        }
        return max(a, b);
    }
    long long maxGcd(int N) {
        if(N==4)return 12;
        return max(lcm(N),lcm(N-1));
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
