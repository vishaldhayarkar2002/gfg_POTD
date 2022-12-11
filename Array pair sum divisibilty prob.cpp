/*
An Efficient Solution is to use Hashing.

1) If length of given array is odd, return false. 
    An odd length array cannot be divided into pairs.
2) Traverse input array and count occurrences of 
    all remainders (use (arr[i] % k)+k)%k for handling the case of negative integers as well). 
      freq[((arr[i] % k) + k) % k]++
3) Traverse input array again. 
   a) Find the remainder of the current element.
   b) If remainder divides k into two halves, then
      there must be even occurrences of it as it 
      forms pair with itself only.
   c) If the remainder is 0, then there must be 
      even occurrences.
   d) Else, number of occurrences of current 
      the remainder must be equal to a number of 
      occurrences of "k - current remainder".*/

// A C++ program to check if arr[0..n-1] can be divided
// in pairs such that every pair is divisible by k.
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        // An odd length array cannot be divided into pairs
        if (n & 1) return false;

        // Create a frequency array to count occurrences
        // of all remainders when divided by k.
        map<int, int> freq;

        // Count occurrences of all remainders
        for (int i = 0; i < n; i++) freq[nums[i] % k]++;

        // Traverse input array and use freq[] to decide
        // if given array can be divided in pairs
        for (int i = 0; i < n; i++) {
            // Remainder of current element
            int rem = nums[i] % k;

            // If remainder with current element divides
            // k into two halves.
            if (2 * rem == k) {
                // Then there must be even occurrences of
                // such remainder
                if (freq[rem] % 2 != 0) return false;
            }

            // If remainder is 0, then there must be two
            // elements with 0 remainder
            else if (rem == 0) {
                if (freq[rem] & 1) return false;
            }

            // Else number of occurrences of remainder
            // must be equal to number of occurrences of
            // k - remainder
            else if (freq[rem] != freq[k - rem])
                return false;
        }
        return true;
    }
};