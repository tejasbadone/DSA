#include <bits/stdc++.h>
using namespace std;

// Bruteforce - Use any sorting algo, here using merge algo
//              T.C. -> O(nlogn), S.C. -> O(n)


// Better - declaring three ints to count 0, 1 and 2 resp. then using three for loops and counts to generate sorted array.
//          TC -> O(2n) -> O(n), SC-> O(1)


// Optimal - Using Dutch National Flag Algorithm.
//             nums[mid] == 0   => swap(nums[mid], nums[low]);  low++;   mid++;
//             nums[mid] == 1   => mid++;
//             nums[mid] == 2   => swap(nums[mid], nums[high]); high--;
//          TC -> O(n), SC -> O(1) 






void sort012Better(int &a[], int n)
    {
        int count0=0, count1=0, count2=0;
        for(int i=0; i<n; i++){
            if(a[i] == 0){
                count0++;
            }
            if(a[i] == 1){
                count1++;
            }
            if(a[i] == 2){
                count2++;
            }
        }
        for(int i=0; i<count0; i++){
            a[i] = 0;
        }
        
        for(int i=count0; i<count0+count1; i++){
            a[i] = 1;
        }
        
        for(int i=count0+count1; i<n; i++){
            a[i] = 2;
        }
    }


void sort012Optimal(vector<int>& nums) {
        int n = nums.size();
        int low=0, mid=0, high = n-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }





