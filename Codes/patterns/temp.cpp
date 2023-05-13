#include <bits/stdc++.h>
using namespace std;



int getMax(int arr[], int size){

    int sum =0;
    // int a = INT_MIN;

    for(int i = 0; i < size; i++)
    {

        sum += arr[i];

        // if(arr[i] > a)
        // {
        //     a = arr[i];
        // }

        // a = max(a, arr[i]);
        
        
    }
    return sum;


}

void reverseArr(int arr[], int size){
    int s = 0;
    int e = 1;

    while(e<size)
    {   
        swap(arr[s],arr[e]);
        s+=2;
        e+=2;
        
    }   

}

bool Uniq(vector<int> arr, int size){

    int count =0;
    vector<int> c;


    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
            
        }

        c.push_back(count);
        


    sort(c.begin(),c.end());
    for(int j = 0; j < c.size(); j++){
        if(c[i] == arr[j]+1)
        {
            return false;
        }
            
    }
    }

    return true;    

}


int main(){

    
    // cout << "Enter the Size" << endl;
    // cin >> size;
    int ans = 1;

    // cout << "Enter the array elements" << endl;
    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};

    int size = sizeof(arr)/ sizeof(int);

    // for(int i = 0; i < size; i++) 
    // {
    //     cin >> arr[i];
    // }

    // Uniq(arr, size);
    
    // cout << reverseArr(arr, size) << endl;
    // cout << "the max and min from the array is " << getMax(arr,size) << endl;

 
    cout << Uniq(arr, size);



    return 0;
}