#include <bits/stdc++.h>
using namespace std;


    int largest(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        
        return arr[n-1];
        
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

    cout << largest(arr, n);

    return 0;
}