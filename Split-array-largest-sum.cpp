#include <bits/stdc++.h>
using namespace std;
/*
1. Use Binary Search.
2. The answer will always lie between max(arr) and sum(arr).
3. To check if mid is maximum subarray sum possible.
 Maintain a count of sub – arrays, include all possible elements in sub array until their sum is less than mid.
After this evaluation, if the count is less than or equal to K, then mid is achievable else not. 
(Since if the count is less than K, we can further divide any subarray its sum will never increase mid).
Find the minimum possible value of mid which satisfies the condition.*/

class Solution {
  public:
    // Function to check if mid can
    // be maximum sub - arrays sum
    bool check(int mid, int array[], int n, int K)
    {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
     
            // If individual element is greater
            // maximum possible sum
            if (array[i] > mid)
                return false;
     
            // Increase sum of current sub - array
            sum += array[i];
     
            // If the sum is greater than
            // mid increase count
            if (sum > mid) {
                count++;
                sum = array[i];
            }
        }
        count++;
     
        // Check condition
        if (count <= K)
            return true;
        return false;
    }
    
    // Function to find maximum subarray sum
    // which is minimum
    int splitArray(int arr[] ,int N, int K) {
        
        int* max = max_element(arr, arr + N);
        int start = *max;
        int end = 0;
     
        for (int i = 0; i < N; i++)
            end += arr[i];
     
        // Answer stores possible
        // maximum sub array sum
        int answer = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
     
            // If mid is possible solution
            // Put answer = mid;
            if (check(mid, arr, N, K)) {
                answer = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
     
        return answer;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
