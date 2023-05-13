#include <bits/stdc++.h>

using namespace std;


// push maximum at the end in each iteration by adjacent swaps

// Time complixity -> Avg & Wrost - O(n2), Best - O(n) ie when no swaps is done



void bubble_sort(int arr[], int n){
    for(int i = n-1; i>=1 ; i--){
        int didSwap = 0;
        for(int j = 0; j<=i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                didSwap = 1;
            }
        }

        if(didSwap == 0){
            break;
        }
    }
}





int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout <<  arr[i] << " ";
    }


    return 0;
}