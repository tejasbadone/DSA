#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    int arr[5];
    int count = 0;

    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];


        for(int j = 1; j < 5; j++)
        {
            if(arr[i] == arr[j]){
                count++;
            }
        }
        
        
    }
    
    cout << count;

}