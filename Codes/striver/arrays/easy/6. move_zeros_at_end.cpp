#include <bits/stdc++.h>
using namespace std;


    void moveZeros(int (&arr)[], int n)
    {
	    int count=0;

        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                count++;
                for(int j = i+1; j<n; j++){
                    
                    arr[i] = arr[j];
                    
                }
            }
        }
        for(int i = n - count ; i<n; i++){
            arr[i] = 0;
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

    moveZeros(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
        
    }

    return 0;
}