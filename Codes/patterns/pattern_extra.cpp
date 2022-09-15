#include <bits/stdc++.h>
using namespace std;


//      * * * * *
//        * * * *
//          * * *
//            * *
//              *


int main(){
    int n;
    int limit=5;
    cout << "Enter the value of n: ";
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=1; j<=i; j++){
           cout << "  ";
        } 
        for(int k = i; k <n; k++)
        {
            cout << "* ";
        }
        
        
        cout << endl;
    }

    return 0;

}