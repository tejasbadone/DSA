#include <bits/stdc++.h>
using namespace std;

// int evendevide(int n){
//     int count = 0;
//     while(n!=0){
//         n = n/10;
//         count++;
//     }
//     return count;
// }


int main(){
    int a=1;
    int b = 2;

    if(a-- > 0 && ++b > 2)  
    {
        cout << "Stage1 - Inside if" << endl;
    } else 
    {
        cout << "Stage2 - INside else";
    }
    
    // cin >> a;
    cout << a << " " << b << endl;
    
    



    return 0;
}