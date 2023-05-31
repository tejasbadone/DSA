#include <bits/stdc++.h>
using namespace std;

// Bruteforce-
// use a extra temp array to store non zeros and then push those at front of original array and insert zeros at the 
// end by using for loop, for(int i = arr.size() - temp.size(); i<arr.size() ; i++) --> TC -> O(n) & SC -> O(n)

// Optimal way - 
// use 2 pointer method, firstly, initialize j = -1 , run a loop to find the index of first zero and assign it to j.
// then, check run another for loop with i = j+1  and check if i != 0 && j != -1, if true swap with the j and j++.






    void moveZeros(int (&arr)[], int n)
    {
	    int j=-1;
        for(int i = 0; i< n; i++){
            if(arr[i] == 0){
                j = i;
                break;
            }
        }
        for(int i = j+1; i<n;i++){
            if(arr[i] != 0 && j != -1){
                swap(arr[j], arr[i]);
                j++;
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

    moveZeros(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
        
    }

    return 0;
}