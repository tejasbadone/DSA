#include <bits/stdc++.h>
using namespace std;

//      12345
//      1234
//      123
//      12
//      1

int main(){
    int n, k=0;
    cout << "Enter value of n" << endl;
    cin >> n;

    for(int i=0; i<n;i++){
        for(int j = 1; j <= n-k; j++)
       {
         cout << j;
        }
        cout << endl;
        k++;
        
    }
    return 0;

}