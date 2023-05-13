#include <bits/stdc++.h>

using namespace std;


// select minimum and swap



void selection_sort(int arr[], int n){
    for(int i =0; i<=n-2; i++){
        int mini = i;
        for(int j = i; j <= n-1; j++)
        {
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
        
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

    selection_sort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout <<  arr[i] << " ";
    }


    return 0;
}