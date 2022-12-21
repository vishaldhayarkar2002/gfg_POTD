#include <bits/stdc++.h> 
using namespace std; 
/*
Step 1: Run a loop from 0 to less then n-1, n is size of the array.
Step 2: Find maximum of the form (arr[i]+i) [say max1], 
maximum of the form (arr[i]-i) [say max2], minimum of the form (arr[i]+i) [say min1]
and minimum of the form (arr[i]-i) [say min2]. 
Step 3: Return the maximum of (max1-min1) and (max2-min2)*/

class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
    
    	int max1 = INT_MIN, min1 = INT_MAX; 
    	int max2 = INT_MIN, min2 = INT_MAX; 
    
    	for (int i = 0; i < n; i++) { 
    	    
    		max1 = max(max1, arr[i] + i); 
    		min1 = min(min1, arr[i] + i); 
    		max2 = max(max2, arr[i] - i); 
    		min2 = min(min2, arr[i] - i); 
    	} 
    
    	return max(max1 - min1, max2 - min2); 
    } 
};

int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 
