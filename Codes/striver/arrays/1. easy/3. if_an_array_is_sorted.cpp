#include <bits/stdc++.h>
using namespace std;


    bool sortedOrNot(int (&arr)[], int n)
    {
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i] > arr[i +1]){
                return 0;
                break;
            }
        }

        return 1;
        
    }


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        
    }

    cout << sortedOrNot(arr, n);

    return 0;
}