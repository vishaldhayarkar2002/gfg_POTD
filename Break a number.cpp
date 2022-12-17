/*
 Efficient Approach: If we carefully observe the test cases
 then we realize that the number of ways to break a number n into 3 parts
 is equal to (n+1) * (n+2) / 2. */
 
class Solution{   
public:
    int waysToBreakNumber(int N)
    {
        int mod = 1e9+7;
        long long int ans = (N+1)%mod;
        ans = ((ans%mod)*((N+2)%mod))%mod;
        ans/=2;
        ans%=mod;
        return ans;
    }
};