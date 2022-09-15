// Find the largest sum of subarray
// Kadane's algorithm O(n)
// output - 11


#include <bits/stdc++.h>
using namespace std;

int maximum_subarray(int arr[], int n){
    int currentSubarray = 0;
    int largestSubarray = 0;

    for(int i=0; i<n; i++){
        currentSubarray = currentSubarray + arr[i];
        if(currentSubarray < 0)
        {
            currentSubarray = 0;
        }
        largestSubarray = max(largestSubarray, currentSubarray);        
    }
    return largestSubarray;
}

int main(){
    int arr[] = {-2, 3, 4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);

    cout << maximum_subarray(arr, n) << endl;

    return 0;
}