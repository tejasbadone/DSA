#include <bits/stdc++.h>
using namespace std;

// Optimal - declare maxi and count with 0. in a for loop if arr[i]==1 count++ and maxi = max(count, maxi), else count = 0;
//           T.C. -> O(n) , S.C. -> O(1)

    int MaxOnes(vector<int> &arr, int n)
    {
        int maxi=0;
        int count=0;

        for(int i=0;i<n;i++){
            if(arr[i] == 1){
                count++;
                maxi = max(maxi, count);
            } else{
                count = 0;
            }
            
        }
        return maxi;

    }




int main(){
    int n;
    cin >> n;
    vector <int> arr;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

   cout << MaxOnes(arr, n) << endl;

    // for(int i = 0; i < n; i++)
    // {
        
    //     cout << arr[i];
    // }

    return 0;
}