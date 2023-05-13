#include <bits/stdc++.h>
using namespace std;


    int slargest(int (&arr)[], int n)
    {
        int largest = INT_MIN;        
        int sLargest = INT_MIN;

        for(int i = 0; i < n; i++){
            if(arr[i] > largest){
                sLargest = largest;
                largest = arr[i];
            }
            else if(arr[i] > sLargest && arr[i] != largest)
            {
                sLargest = arr[i];
            }
            
        }       
        return sLargest;
    }


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        
    }

    cout << slargest(arr, n);

    return 0;
}