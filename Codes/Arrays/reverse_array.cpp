// time complexity - O(n)


#include <bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int n){
    int s = 0;
    int e = n-1;

    while(s<e){
        swap(arr[s],arr[e]);
        s += 1;
        e -=1;
    }

}



int main(){
    int arr[] = {2,5,9,10,12,15,20,30,45,50,100};

    int n = sizeof(arr)/ sizeof(int);

    
    for(int i =0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    reverse_array(arr, n);

    for(int i =0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}