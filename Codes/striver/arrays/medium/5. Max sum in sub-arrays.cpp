#include <bits/stdc++.h>
using namespace std;


long long pairWithMaxSum(long long arr[], long long N)
    {
        long long maxi=0;
        long long sum =0;
        
        for(int i=0; i<N-1; i++){
            sum = arr[i] + arr[i+1];
            maxi = max(maxi, sum);
        }
        return maxi;
    }