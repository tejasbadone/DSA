#include <bits/stdc++.h> 
using namespace std; 


// In main fun, the size of the array is n. but in other function it is just 
// the address and it is stored in pointers which is of 8 bytes
// therefore size of array in main - 24 Bytes
// size of array in other functions - 8 Bytes


void printArray(int * arr, int n){
    cout << "In funtion - " << sizeof(arr) << endl;
    arr[0] = 100;
    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
}



int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};

    int n = sizeof(arr)/sizeof(int);

    cout << "In Main - " << sizeof(arr) << endl;

    printArray(arr,n);

    for(int i=0; i<n; i++){
        cout<< arr[i] << endl;
    }
    
    return 0;

}
