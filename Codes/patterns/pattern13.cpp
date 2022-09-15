#include <bits/stdc++.h>
using namespace std;

//      ****
//      *  *
//      *  *
//      *  *
//      ****

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    for(int j = 0; j < n-1; j++){
        cout<< "* "; 
    }
    cout << endl;

    for(int i = 0; i < n-2; i++)
    {
        for(int j = 0; j < n-1; j++){
            if(j>0 && j<n-2){
                cout << "  ";
            } else {
                cout << "* ";
            } 
    }
        cout << endl;

    }
    for(int j = 0; j < n-1; j++){
        cout<< "* "; 
    }      
    
    return 0;
    
}


