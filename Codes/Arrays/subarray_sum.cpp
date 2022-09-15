// Find the largest sum of subarray
// bruteforce method O(n^3) & prefix sum method O(n^2)
// output - 11


#include <bits/stdc++.h>
using namespace std;

int largestSum = 0;

int subarray_sum(int arr[], int n){
    

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            int subarraySum = 0;

            for(int k=i; k<=j; k++){
                subarraySum += arr[k];
            }

            // put a check is subarraySum > largestSum
            largestSum = max(largestSum,subarraySum);
        }
    }

    return largestSum;
}

int prefixSum(int arr[], int n){
    int prefix[100] = {0};
    prefix[0] = arr[0];

    for(int i=1; i<n; i++){
        prefix[0] = prefix[i-1] + arr[i];
    }

    // largest sum login
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int subarraySum = i > 0 ? prefix[j] - prefix[i-1] : prefix[j];
            largestSum = max(largestSum, subarraySum);
        }
    }

    return largestSum;



}


int main(){
    int arr[] = {-2, 3, 4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);

    cout << subarray_sum(arr, n) << endl;

    cout << prefixSum(arr, n) << endl;

    return 0;
}