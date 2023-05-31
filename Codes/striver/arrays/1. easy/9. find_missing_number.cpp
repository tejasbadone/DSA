#include <bits/stdc++.h>
using namespace std;

// Bruteforce - use a flag system, declare a int flag as 0 and by using two nested loops(i=1, j=0) check if the arr[i]==j -> flag=1;
//              later check if the flag is still zero, that is our missing index, return it.
//              T.C. -> O(n*n), S.C. -> O(1)


// Better - Using Hashmap, create a hash array of size n+1 and mark all input array elements as 1, then in another for loop check
//          if hash[i] == 0, if yes-> return i;
//          T.C. -> O(n)+O(n), S.C. -> O(n)

// Optimal - 2 optimal solutions ie Sum and XOR,
//           1 -> Sum, using all natural numbers formula getting sum of array in int sum, and getting sum of elements in array in int s2 
//                returning sum-s2. T.C. -> O(n) , S.C. -> O(1)

//           2 -> using XOR, declare two ints xor1 and xor2 with 0. run a for loop from 0 to N (ie n-1, to save a extra for loop) and
//                XOR all array elements and store it in xor2(this will generate some number) also XOR (i+1) to xor1 and store in xor1.
//                after for loop, XOR xor1 with n(so that we could find the missing element). finally return xor1^xor2.

//              T.C. -> O(n) , S.C. -> O(1)




    int findMBrute(vector<int> &arr, int n)
    {
        // TLE
        sort(arr.begin(), arr.end());
        for(int i = 1 ; i <= n;i++){
            int flag = 0;
            for(int j =0; j<=n-1 ; j++){
                if(arr[j] == i){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                return i;
            }
        }
        return -1;

    }

    int findMBetter(vector<int> &arr, int n)
    {
        
        int hash[n+1] = {0};
        for(int i=0; i<=n; i++){
            hash[arr[i]] = 1;
        }
        for(int i=1; i<=n; i++){
            if(hash[i] == 0){
                return i;
            }
        }

        return -1;

    }

        int findMOptimalSum(vector<int> &arr, int n)
    {
        
        int sum = n*(n+1)/2;
        int s2 = 0;

        for(int i=0; i<n-1; i++){
            s2 += arr[i];
        }

        return (sum-s2);

    }



    int findMOptimalXor(vector<int> &arr, int n)
    {
        int xor1=0, xor2=0;
        int N = n-1;

        for(int i=0;i<N;i++){
            xor2 = xor2^arr[i];
            xor1 = xor1^(i+1);
        }
        xor1 = xor1^n;
        return xor1^xor2;

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

   cout << findMOptimalXor(arr, n);

    // for(int i = 0; i < n; i++)
    // {
        
    //     cout << arr[i];
    // }

    return 0;
}