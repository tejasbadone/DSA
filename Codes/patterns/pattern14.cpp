#include <bits/stdc++.h>
using namespace std;

//      1      1
//      12    21
//      123  321
//      12344321

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j;
        }

        for(int k = i; k < n-1; k++)
        {
            cout << " ";
        }

        for(int k = i; k < n-1; k++)
        {
            cout << " ";
        }

        for(int j = i; j >=1 ; j--)
        {
            cout << j;
        }
        

        cout << endl;
        
    }

    return 0;
    
}