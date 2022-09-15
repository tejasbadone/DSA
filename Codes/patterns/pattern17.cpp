#include <bits/stdc++.h>
using namespace std;


// 1 
// 2 3 
// 4 5 6
// 7 8 9 10 
// 11 12 13 14 15 


int main(){
    int n=1;
    int num = 5;
    // cout << "Enter the value of n: ";
    // cin >> n;

    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << n << ' ';
            n++;
            
        }

        cout << endl;
        
    }

    return 0;
    
}