#include <bits/stdc++.h>

using namespace std;


// -> Pick a pivot and place it in its correct place in the sorted array
// -> smaller than pivot is on the left and greater on the right side



    int partition (vector<int> &arr, int low, int high)
    {
       int pivot = arr[low];
       int i = low;
       int j = high;
       
       while(i < j){
           while(arr[i] <= pivot && i <= high - 1){
               i++;
           }
           while(arr[j] > pivot && j >= low + 1){
               j--;
           }
           if(i < j) {
               swap(arr[i] , arr[j]);
           }
       }
       swap(arr[low], arr[j]);
       return j;
    }


    void quickSort(vector<int> &arr, int low, int high)
    {
        if(low < high){
            int pIndex = partition(arr, low, high);
            quickSort(arr, low , pIndex - 1);
            quickSort(arr, pIndex+1 , high);
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

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        cout <<  arr[i] << " ";
    }


    return 0;
}