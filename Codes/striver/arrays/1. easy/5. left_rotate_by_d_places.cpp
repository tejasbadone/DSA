#include <bits/stdc++.h>
using namespace std;


    void rotate(vector<int> &arr, int n, int k)
    {
        k = k%n;
        vector<int> temp;

        for(int i =0; i< k; i++){
            temp.push_back(arr[i]);
        }

        for(int i=k ; i < n; i++){
            arr[i-k] = arr[i];
        }
        for(int i = n-k; i<n;i++){
            arr[i] = temp[i - (n-k)];
        }

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
    int k;
    cin >> k;

    rotate(arr, n, k);

    for(int i = 0; i < n; i++)
    {
        
        cout << arr[i];
    }

    return 0;
}