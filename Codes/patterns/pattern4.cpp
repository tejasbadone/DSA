#include <bits/stdc++.h>
using namespace std;


//      1
//      22 
//      333
//      4444
//      55555


int main(){
    int n;
    cout<< "Enter the value of n" << endl;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<< i << " ";
        }
        cout<<endl;
    }
}