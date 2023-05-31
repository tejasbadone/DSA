#include <bits/stdc++.h>
using namespace std;


// Bruteforce - Generate all permutations. Linear search to find the given permutation. The permutation next to the given is the ans.
//              if the permutation is the highest/largest last permutation, the first permutation is the ans.

//              IN AN INTERVIEW JUST TELL STEPS. DONT START TO CODE BRUTEFORCE CAUSE IT WILL TAKE ALOT TIME. TELL INTERVIEWER
//              THIS WILL TAKE COMPLEXITY OF HIGH ORDER(IE O(N!*N)) THAT IS WHY I LL TRY TO OPTIMISE IT.

//              TC -> O(n! * n).

// Better - Use C++ STL;

// Optimal - (implement C++'s STL next_permutation)
//              1. Find the Breaking point. finding the smallest element from the last of the array.
//                theoretically start drawing graph from the last element of array, the graph should give a increasing curve. 
//                if any element of arr breaks the graph curve, that index is our breaking point. to get this declare int index = -1.
//                run a loop from n-2 till i>=0 and i--, if arr[i] < arr[i+1] then index = i.
//              2. if index == -1 (ie theres no breaking point/of graph and the current input array is the highest last permutation),
//               the next permutation will be the reverse of given arr. ie the very first permutation of arr.
//              3. find the exact next greater element than arr[index] and swap them. run a loop from i=n-1 till i>index, i--.
//               if arr[i] > arr[index], swap() and break.
//              4. reverse the subarray to get lowest next premutation with remaining elements. using reverse(arr.begin()+index+1, arr.end())
//              
//              TC - > O(3n), SC - > O(1), modifying the array -> O(n)




vector<int> nextPermutationBetter(vector<int>& arr) {
    next_permutation(arr.being(), arr.end());
    return arr;
}

vector<int> nextPermutationOPtimal(vector<int>& arr) {
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int index = -1;

        for(int i = n-2; i>= 0; i--){
            if(arr[i] < arr[i+1]){
                index = i;
                break;
            }
        }
        
        if(index == -1){
            reverse(arr.begin(), arr.end());
            return;
        } 
        else {
            for(int i=n-1; i>index; i--){
                if(arr[i] > arr[index]){
                    swap(arr[i], arr[index]);
                    break;

                }
            }
        }
        reverse(arr.begin()+index+1, arr.end());
    }
}


