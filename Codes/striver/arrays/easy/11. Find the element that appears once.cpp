#include <bits/stdc++.h>
using namespace std;

// Bruteforce - use nested loop approach, in first for loop declare num = arr[i] and count =0. in second for loop j=0 -> n if(arr[j] == num)
//              count++. after first loop if count==1 , return num. 
//              T.C. -> O(n*n), S.C. -> O(1)


// Better - 1. Using Hashing, but we dont know the size for the hash array, for that run a for loop and get max no of elements and declare hash array with size.
//          run a for loop hash[arr[i]]++; and one final for loop to check if hash[arr[i]] == 1 is true return arr[i]
//          TC -> O(3n), SC-> O(n)
//          
//          cannot use hash arrays for much elements or -ve numbers, therefore use maps DS as a hashing table.


// Optimal -   use XOR, xor1 = xor1 ^ arr[i]; this will cancel out all similar element except the ans
//              T.C. -> O(n) , S.C. -> O(1)




    int findOBrute(vector<int> &arr, int n)
    {
        for(int i=0; i<n;i++){
            int numb = arr[i];
            int count =0;
            for(int j=0; j<n;j++){
                if(arr[j] == numb){
                    count++;
                }
            }
            if(count == 1) {
                return numb;
                break;
            }
        }
        return -1;        

    }

    int findOBetterArr(vector<int> &arr, int n)
    {
        int maxi = arr[0];
        for(int i=0;i<n;i++){
            maxi = max(maxi, arr[i]);
        }

        int hash[maxi+1] = {0};

        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }

        for(int i=0;i<n;i++){
            if(hash[arr[i]]==1){
                return arr[i];
            }
        }
        return -1;       
    }


    int findOOptimal(vector<int> &arr, int n)
    {
        
        int xor1= 0;
        for(int i=0;i<n;i++){
            xor1 = xor1 ^ arr[i];
        }
        return xor1;

    }



    int findOYourSolution(vector<int> &arr, int N)
    {
        int i =0;
	    int j= i+1;
	    
	    while(i<=N-1 && j<=N){
	        if(arr[i] == arr[j]){
	            i = j+1;
	            j = i+1;
	        } else {
	            return arr[i];
	            break;
	        }
	    }
	    
	    return -1;

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

   cout << findOBetterArr(arr, n);

    // for(int i = 0; i < n; i++)
    // {
        
    //     cout << arr[i];
    // }

    return 0;
}