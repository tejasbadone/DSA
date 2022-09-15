#include <bits/stdc++.h>
using namespace std;

//      * 
//      * *
//      * * * 
//      * * * *
//      * * * * *
//      * * * *
//      * * * 
//      * *
//      * 

int main(){
    int n;
    cout << "Enter value of n: "<< endl;
    cin>>n;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << "* ";
        }

        cout << endl;
        
    }
    for(int l = 1; l < n; l++)
    {
        for(int k = l; k < n; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    
    
}