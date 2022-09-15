#include <bits/stdc++.h>
using namespace std;

//     A
//    ABA
//   ABCBA
//  ABCDCBA 

int main(){
    char n;
    cin >>n;

    for(char i = 'A'; i < n; i++)
    {
        for(char j = i; j < n; j++)
        {
            cout << " ";
        }

        for(char j = 'A'; j < i; j++)
        {
            cout << j;
        }

        for(char j = i; j >= 'A'; j--)
        {
            cout << j;
        }

        cout << endl;
        
    }

    return 0;
    
}