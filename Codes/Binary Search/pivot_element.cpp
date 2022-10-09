#include <bits/stdc++.h>
using namespace std;



// find lowest element in an array with log(n) complexity

int pivotElement(int arr[],int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    while(s<e)
    {

        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else 
        {
            e = mid;
        }
        mid = s+(e-s)/2;

    }

    return mid;
    
    


}

int main(){
    int arr[] = {7,9,10,12,1,2,3};
    int size = sizeof(arr)/ sizeof(int);

    int ans = pivotElement(arr,size);

    cout << ans;

    return 0;

}