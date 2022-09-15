#include <bits/stdc++.h>
using namespace std;


    //          *
	//         ***
	//        *****
	//       *******
	//      ********* 


int main(){
    int n, calc;
    
    cout<< " Enter the value of n" << endl;
    cin >> n;

    calc = (2*n)/2;

    int right=calc+1, left=calc-1;
        // 6               4

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <(2*n); j++)
        {
            if(j < calc && j <= left )
            {
                cout<< "  ";
            } else if(j>calc && j >= right)
            {
                cout<< "  ";
            } else {
                cout << "* ";
            }
            
        }
        cout << endl;
        right++;
        left--;
        
    }

    return 0;

    
}