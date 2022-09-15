#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int key){
    for(int i = 0; i<n; i++){
        if(arr[i]==key)
        {
            return i;
        }
        
    }

    return -1;
}





int main(){

    int arr[] = {10, 15, 20, 65, 95, 43, 2, 3, 7};

    // find number of elements in the array
    int n = sizeof(arr)/ sizeof(int);

    int key;
    cin >> key;
    
    int index = linear_search(arr, n, key);

    if(index != -1){
        cout << key << " is present in the array at " << index << endl;
    } else 
    {
        cout << key << " is NOT FOUND!" << endl;
    }

    return 0;

}