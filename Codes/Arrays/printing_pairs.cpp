#include <bits/stdc++.h>
using namespace std;

// printing all pairs with next(right side's) elements

void print_paires(int arr[], int n){
    for(int i = 0; i < n; i++){
        int x = arr[i];
        for(int j = i+1; j<n; j++){
            int y = arr[j];

            cout << x << "," << y << endl;
        }
        cout << endl;
    }
}



int main(){
    int arr[] = {2,5,9,10,12};
    int n = sizeof(arr)/sizeof(int);

    print_paires(arr, n);

    return 0;
}