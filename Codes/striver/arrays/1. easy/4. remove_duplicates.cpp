#include <bits/stdc++.h>
using namespace std;


    int removeD(vector<int> &arr)
    {
        int i = 0;
        for(int j = 1; j<arr.size(); j++){
            if(arr[i] != arr[j]){
                arr[i+1] = arr[j];
                i++;
            }
        }
        return i+1;
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

    int ans = removeD(arr);

    for(int i = 0; i < ans; i++)
    {
        
        cout << arr[i];
    }

    return 0;
}