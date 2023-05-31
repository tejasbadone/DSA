#include <bits/stdc++.h>
using namespace std;

// Bruteforce-
// Use a set and a temp unione array to store the union elements. firsly push all elements in 
// set and then push set elements in temp union array

// Optimal way - 
// use 2 pointer method and use while loops, firsly declare i and j with 0, then while i<n && j<m, compare elements of both array and push
// smaller to the union temp array, inside if again check if the unionArr.back() != arr1[i] && unionArr.size != 0 if it not not 
// present push the element in unionArr, increment respective index.
// it is possible that one array could get exausted in that case use 2 while loops and check the upper case.






    vector<int> unionF(vector<int> arr1, vector<int> arr2, int n, int m)
    {
	    int i=0, j=0;
        vector<int> unionArr;
        while(i<n && j<m){
            if(arr1[i] <= arr2[j]){
                if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
                    unionArr.push_back(arr1[i]);
                }
                i++;
            } else {
                if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
                    unionArr.push_back(arr2[j]);
                }
                j++;
            }
        }
        while(i<n){
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
                    unionArr.push_back(arr1[i]);
                }
                i++;
        }
        while(j<m){
            if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
                    unionArr.push_back(arr2[j]);
                }
                j++;
        }
        return unionArr;
        
    }


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr1, arr2;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr1.push_back(temp);
        
    }

    for(int i = 0; i < m; i++)
    {
        
        int temp;
        cin >> temp;
        arr2.push_back(temp);
        
    }

    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr1[i] << " " ;
        
    // }
    // for(int i = 0; i < m; i++)
    // {
    //     cout << arr2[i] << " " ;
        
    // }

    vector<int> ans = unionF(arr1, arr2, n,m);

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " " ;
        
    }

    return 0;
}