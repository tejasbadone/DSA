#include <bits/stdc++.h>
using namespace std;

//          **********
//          ****  ****
//          ***    ***
//          **      **
//          *        *
//          *        *
//          **      **
//          ***    ***
//          ****  ****
//          **********

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    
    for(int i=0;i<n;i++){
        for(int j = i; j < n; j++)
        {
            cout << "*";
        }
        for(int k = 0; k < i; k++)
        {
            cout << " ";
        }
        for(int m = 0; m < i; m++)
        {
            cout << " ";
        }
        for(int l = i; l <n; l++)
        {
            cout << "*";
        }
        cout<< endl;
    }

    for(int i=0;i<=n;i++){
        for(int j = 0; j <i; j++)
        {
            cout << "*";
        }
        for(int k = i; k < n; k++)
        {
            cout << " ";
        }
        for(int m = i; m < n; m++)
        {
            cout << " ";
        }
        for(int l = 0; l <i; l++)
        {
            cout << "*";
        }
        cout<< endl;
    }

    return 0;
    
}


