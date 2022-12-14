/*
Intuition :
Convert the string to an array of -1 or 1, where each '0' and '1' converted to 1 and -1 respectively. 
Now find the maximum subarray sum and the indices. If string contains all '0' then return -1 as an array.
Use Kadane's Algo to find maximum subarray sum.
Implementation :
The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum contiguous subarray
ending at current index and a variable max_so_far stores the maximum sum of contiguous subarray found so far,
Everytime there is a positive-sum value in max_ending_here compare it with max_so_far and 
update max_so_far if it is greater than max_so_far.
Initialize the variables s, start, and end with 0 and max_so_far = INT_MIN and max_ending_here = 0
Run a for loop form 0 to N-1 and for each index i:
Add the arr[i] to max_ending_here.
If max_so_far is less than max_ending_here then update max_so_far to max_ending_here and update start to s and end to i .
If max_ending_here < 0 then update max_ending_here = 0 and s with i+1.
Return values from index start to end.*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findRange(string str, int n) {
        int max_so_far = INT_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;
        bool allOne = true;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') allOne = false;
        }
    
        vector<int> ans;
        if (allOne) {
            ans.push_back(-1);
            return ans;
        }
        for (int i = 0; i < n; i++) {
            max_ending_here += (str[i] == '1' ? -1 : 1);
    
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
    
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
    
        ans.push_back(start + 1);
        ans.push_back(end + 1);
    
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends