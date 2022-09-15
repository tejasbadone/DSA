#include <bits/stdc++.h>
using namespace std;

//      E 
//      D E
//      C D E
//      B C D E
//      A B C D E



int main(){
    int n;
    cin >> n;
    int num = 'A';

    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <=i; j++)
        {
            cout << char((num + n)-1) << ' ';
            num++;
        }
        num = num -i -1;
        cout << endl;
        
    }

    return 0;    

}