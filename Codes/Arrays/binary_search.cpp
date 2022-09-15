// works on sorted arrays or monotic(non decreasing and non increasing graph)

#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int key){
    int s = 0;

    // end = n-1 (index of last element)
    int e = n-1;

    while(s<=e){
        int mid = (s+e)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else {
            s = mid + 1;
        }
    }
    return -1;
    
}





int main(){

    int arr[] = {2,5,9,10,12,15,20,30,45,50,100};

    // find number of elements in the array
    int n = sizeof(arr)/ sizeof(int);

    int key;
    cin >> key;
    
    int index = binary_search(arr, n, key);

    if(index != -1){
        cout << key << " is present in the array at " << index << endl;
    } else 
    {
        cout << key << " is NOT FOUND!" << endl;
    }
    return 0;

}