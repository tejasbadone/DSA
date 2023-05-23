#include <bits/stdc++.h>
using namespace std;

// Bruteforce - Generate all subarrays and find everyone's sum and whichever is longest, that's the ans. 
//              T.C. -> O(n*n), S.C. -> O(1)


// Better - Using Hashing, use map as hash table w/ long long as key and int as value <long long, int>. get sum of all elements in s,
//          maxLen = max(maxLen, i+1). get remaining value by rem = sum - k and check if the rem is already present in the map
//          ie(preSumMap.find(rem) != preSumMap.end()). get the length of rem by i-preSumMap[rem] and update maxLen.   
//          if preSumMap.find(sum) == preSumMap.end() then preSumMap[sum] = i and lastly return maxLen.

//          THIS IS THE OPTIMAL SOLUTION FOR THE ARRAY HAVING -VE, +VE AND 0'S 

//          TC -> ordered map(w/ no collisions) -> O(nlogn), 
//                unordered map -> w/ no collisions -> O(n*1), w/ collisions -> O(n*n)
//                SC-> O(n)


// Optimal -   start i and j from 0 of arr. move j to the right and add each j value in sum. if sum==k then get the subarray len by j-i
//             and store it in var len. whenever the sum > k (ie sum exceds k) move the i to right

//             VALUE OF SUM ALWAYS HAS TO BE <= K TO SHIFT J TO RIGHT
//             OPTIMAL OF ARRAY CONTAINS +VE AND 0'S

//              T.C. -> O(2n) , S.C. -> O(1)




    int longestSubBrute(vector<int> &arr, int n, int k)
    {
        int len = 0;
        for(int i=0; i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=arr[j];
                if(s==k){
                    len = max(len,j-i+1);
                }
            }
        }  
        return len;   

    }


    // this code is the optimal solution for the array which have +ve, -ve and 0's
    int longestSubBetter(vector<int> &arr, int n, int k)
    {
        map<long long, int> preSumMap;
        long long sum=0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum == k){
                maxLen = max(maxLen, i+1);
            }
            long long rem = sum - k;
            if(preSumMap.find(rem) != preSumMap.end()){
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if(preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum] = i;
            }
        }       
        return maxLen;
    }


    int longestSubOptimal(vector<int> &arr, int n, int k)
    {
        int left=0, right=0;
        long long sum = arr[0];
        int maxLen = 0;
        while(right<n){
            while(left <= sum && sum > k){
                sum -= arr[left];
                left++;
            }
            if(sum==k){
                maxLen = max(maxLen, right-left+1);
            }
            right++;
            if(right < n){
                sum += arr[right];
            }
        }
        return maxLen;

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

   cout << longestSubOptimal(arr, n, 15);

    // for(int i = 0; i < n; i++)
    // {
        
    //     cout << arr[i];
    // }

    return 0;
}