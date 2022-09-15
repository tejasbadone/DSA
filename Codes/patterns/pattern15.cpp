#include <bits/stdc++.h>
using namespace std;

//      A
//      AB 
//      ABC
//      ABCD
//      ABCDE



// A
// BB
// CCC
// DDDD
// EEEEE


// ABCDE
// ABCD
// ABC
// AB
// A 



int main(){
    
    int num = 5;
    // cout << "Enter the value of n: ";
    // cin >> n;

    for(int i = 1; i <= num; i++)
    {
        char n = 'A';
        for(int j = num; j >= i; j--)
        {
            cout << n;
            n++;
            
        }

        cout << endl;
        
    }

    return 0;
    
}