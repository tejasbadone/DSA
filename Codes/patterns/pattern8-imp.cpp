#include <bits/stdc++.h>
using namespace std;


//      *********
//       *******
//        *****
//         ***
//          *



int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    for(int i=0;i<=n;i++){
        for(int j=1; j<=i; j++){
            cout << "  ";
        } 
        for(int k = i; k <=n; k++)
        {
            cout << "* ";
        }
        for(int m = i; m < n; m++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;

}