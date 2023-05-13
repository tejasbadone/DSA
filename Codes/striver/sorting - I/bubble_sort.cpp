#include <bits/stdc++.h>

using namespace std;


// push maximum at the end in each iteration by adjacent swaps

// Time complixity -> Avg & Wrost - O(n2), Best - O(n) ie when no swaps is done



void bubble_sort(vector<int> &arr, int n){
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


void recursiveBubble(vector<int> &arr, int n)

    {
        if(n==0) return;
        for(int i = 0 ; i < n-1 ; i++){
            if(arr[i] >= arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        } 
        
        recursiveBubble(arr, n-1);
    }


int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {   
        int num;
        cin >> num;
        arr.push_back(num);
    }

    recursiveBubble(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout <<  arr[i] << " ";
    }


    return 0;
}