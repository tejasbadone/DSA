#include <bits/stdc++.h>
using namespace std;

int ifPossible(vector<int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i = 0; i < n; i++)
    {
        if(pageSum+arr[i] <= mid)
        {
            pageSum+= arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i]>mid)
            {
                return false;
            }
            pageSum = arr[i];
            
        }
        
    }

    return true;
    
}




int allocateBooks(vector<int> arr, int n, int m){
    int s=0;
    int sum =0;

    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s+(e-s)/2;

    while(s<=e) 
    {
        if(ifPossible(arr,n,m,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
        
    }
    
    return ans;
}


int main(){
    vector<int> arr = {10,20,30,40};
    int n = 4;
    int m = 2;

    int ans = allocateBooks(arr, n,m);

    cout << ans;

    return 0;

}