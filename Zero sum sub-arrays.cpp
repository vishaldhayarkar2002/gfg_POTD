/*
Implementation
Step 1: Initialize sum and counter with zero
Step 2: Use a map to store the prefix sum which has appeared already, and number of occurrence.
Step 3: iterating over the array.
Step 4: calculate presum
Step 5: if presum equals to zero update the counter
Step 6: if prefix sum is already present in map then it is repeated which means there is a subarray whose summation is 0. 
update the counter by adding the occurrence of the presum value.
Step 7: update the frequency of presum value.
Step 8: Return the counter.*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr ,int n) {
        
        long long int sum=0, counter=0; 
         
         //using map to store the prefix sum which has appeared already.
        unordered_map<long long int,long long int>mp;
        
        //iterating over the array.
        for(int i=0;i<n;i++)
        {
            //storing prefix sum.
            sum+=arr[i];
            
            //if prefix sum is zero that means we get a subarray with sum=0.
            if(sum==0) 
            {
                //incrementing the counter.
                counter++; 
            }
            
            //if prefix sum is already present in map then it is repeated 
            //which means there is a subarray whose summation is 0.
            if(mp.count(sum)!=0) 
            {
               //we add the value at prefix sum in map to counter.
               counter+=mp[sum]; 
            }
            
            //incrementing the count of prefix sum obtained in map.
            mp[sum]++; 
        }
           //returning the counter.
        return counter ;
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
