#include <bits/stdc++.h>
using namespace std;

// Bruteforce-
// Use nested for loops, declare a array with m size and initialise with 0 to keep track of visited element. if the element is visited 
// mark it 1 in vis array.  

// Code - 


    int intersBrute(int a[], int b[], int n, int m) {
        vector<int> intersectionArr;
        int vis[m] = {0};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(a[i] == b[j] && vis[j] == 0){
                    intersectionArr.push_back(a[i]);
                    vis[j] = 1;
                    break;
                }
                if(b[j] > a[i]) break;
            }
        }
        
        return intersectionArr.size();
    }



// Optimal way - 

    int intersOptimal(vector<int> a, vector<int> b, int n, int m)
    {
	    int i=0; 
        int j = 0;
        int count = 0;

        // sort(a, a+n);
        // sort(b , b+m);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        while(i < n && j < m){
            if(i > 0 && a[i] == a[i-1]){
                i++;
                continue;
            }
            if(a[i] < b[j]){
                i++;
            }
            else if(b[j] < a[i]){
                j++;
            } else{
                count++;
                i++;
                j++;
            }
        }
        return count;
        
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

    cout <<  intersOptimal(arr1, arr2, n,m);


    return 0;
}