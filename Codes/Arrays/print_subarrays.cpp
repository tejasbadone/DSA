// subarray - smaller contineous part of array
// 1 2 3 4 5 
// subarray - 1 2 3 or 3 4 5
// not a subarray - 1 2 5 (because it is not contineous)
// DO QUESTIONS ON PATTERN PRINTING


#include <bits/stdc++.h>
using namespace std;

void print_subarrays(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            // cout << "(" << i << "," << j << ")";
            for(int k=i; k<=j; k++){
                cout << arr[k] << ",";
            }
            cout << endl;
        }
    }
}


int main(){
    int arr[] = {2,5,9,10,12};
    int n = sizeof(arr)/sizeof(int);

    print_subarrays(arr, n);

    return 0;
}