#include <bits/stdc++.h>
using namespace std;


// Bruteforce - running a for loop and assigning each element to x and count = 1(as we already taken a element) and checking if x+1 
//              is present in array by using while loop linear search funtion which returns a bool. if it is present then update x=x+1,
//              cnt +=1; if the x+1 is not present, the while loop will break and update the maxi(max count). then for loop will assign 
//              next element in array and will work the same. 
//              TC -> O(n3), SC -> O(1)

//  Better - to get the consecutive series, one has to be greater than its lastelement by 1. therefore using three ints count=0, lastSmaller=INT_MIN
//           and maxi=1(longest consecutive count encountered so far). running a loop and checking if arr[i]-1 == lastSmaller then count++
//           and lastSmaller = arr[i]. elseif(arr[i] != lastSmaller) then count = 0, lastSmaller = arr[i]. update maxi using max() and return it.
//              TC -> O(nlogn) + O(n) -> O(nlogn), SC - > O(1)


// Optimal - Using unordered set, put all elements in set. take each element of set and check if element-1 is present in set. if it is
//           present that means its not the starting point. therefore taking next element of set. if the element-1 is not present in set
//           ie it could be the starting point of consective series, therefore count=1 & storing iterator value to x and using while loop to check
//           if x+1 is present in set or not. if it is, count++ and x+=1(finding the next consecutive elements and updating count). update maxi using max().
//              TC -> O(3n), SC -> O(n)


    // Linear search
    bool ls(int arr[], int x, int n){
        for(int i=0; i<n; i++){
            if(arr[i] == x){
                return true;
            }
        }
        return false;
    }
    
    int findLongestConseqSubseqBrute(int arr[], int n)
    {
        int maxi = 1;
        for(int i=0; i<n; i++){
            int x = arr[i];
            int count = 1;
            while(ls(arr, x+1, n) == true){
                x=x+1;
                count+=1;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }


    int longestConsecutiveBetter(vector<int>& nums) {
        int maxi = 1;
        int lastSmaller = INT_MIN, count = 0;
        int n = nums.size();


        if(n==0) return 0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmaller){
                count +=1;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]){
                count = 1;
                lastSmaller = nums[i];
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }



    int longestConsecutiveOptimal(vector<int>& nums) {
        int maxi =1;
        int n = nums.size();

        if(n==0) return 0;

        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int count =1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x=x+1;
                    count+=1;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }

