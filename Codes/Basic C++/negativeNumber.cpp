#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; n!=0; i++)
    {
        int bit = n&1;
        n = n>>1;
        cout << bit << endl;
    }
    
    // cout << n << endl;
    
    return 0;
}
