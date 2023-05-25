#include <bits/stdc++.h>
using namespace std;

// Bruteforce - Using nested for loops to get all possible combinations of subarrays, and in second loop runing a third loop which 
//              calculates the sum from i to j. updating that sum to maxi var using max(maxi, sum). return maxi.
//              T.C. -> O(n3), S.C. -> O(1)


// Better - Same as above but instead of running a seperate loop for summation, just declare sum in first loop and get summation in sum in second loop
//          from i to j. 
//          TC -> O(n2), SC-> O(1)


// Optimal - Using Kadane's Algorithm. maxi = LONG_MIN. run a loop and get summation of arr in sum var. if sum < 0 then the sum = 0.
//           if sum>maxi then maxi=sum.

//          A SPECIAL CASE W/ CODE IS ADDED TO GET THE START AND END INDEXES OF THE SUBARRAY.

//           TC -> O(n), SC -> O(1) 



    long long maxSubarraySumBrute(int arr[], int n){
        
        long long maxi=LLONG_MIN;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                long long sum = 0;
                for(int k=i; k<=j;k++){
                    sum += arr[k];
                    maxi = max(sum, maxi);
                }
            }
        }
        return maxi;        
    }


    long long maxSubarraySumBetter(int arr[], int n){
        
        long long maxi=LLONG_MIN;
        for(int i=0; i<n; i++){
            long long sum = 0;
            for(int j=i; j<n; j++){
                sum += arr[j];
                maxi = max(sum, maxi);
            }
        }
        return maxi;        
    }


    long long maxSubarraySumOptimal(int arr[], int n){
        
        long long maxi = LONG_MIN;
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > maxi){
                maxi= sum;
            }
            if(sum < 0){
                sum =0;
            }
        }
        return maxi;
    }

    // IMP - get the start and end indexes of the subarray.
    long long maxSubarraySumOptimal(int arr[], int n)
    {        
        long long maxi = LONG_MIN;
        long long sum = 0;
        int start, ansStart, ansEnd;


        for(int i=0; i<n; i++){
            if(sum == 0){
                start = i;
            }

            sum += arr[i];

            if(sum > maxi){
                maxi= sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }



