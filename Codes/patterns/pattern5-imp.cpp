#include <bits/stdc++.h>
using namespace std;


//      *****
//      ****
//      ***
//      **
//      *



int main(){
    int n;
    cout << "Enter value of n" << endl;
    cin >> n;

    for(int i=0; i<n; i++){

        for(int j=i; j<n; j++){
            cout<<"* ";
        }
        
        cout<<endl;
    }
    return 0;
}

// OR


// int main(){
//     int n, k=0;
//     cout << "Enter value of n" << endl;
//     cin >> n;

//     for(int i=0; i<n; i++){

//         for(int j=i; j<n; j++){
//             cout<<"* ";
//         }
//         n--;
//         cout<<endl;
//     }
//     return 0;
// }