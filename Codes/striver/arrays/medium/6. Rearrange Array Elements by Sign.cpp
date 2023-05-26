#include <bits/stdc++.h>
using namespace std;

// Bruteforce - Using 2 extra arrays of size n/2 to store +ve and -ve elements of arr. then running a for loop to update the array
//              arr[2*i] = posArr[i]; and arr[2*i+1] = negArr[i];
//              TC -> O(n)+O(n/2) -> O(n), SC -> O(n)

//  Optimal - declaring a single vector ans of size n with all 0's. declaring posIndex = 0 and negIndex=1. run a loop and check if
//            arr[i] < 0 then ans[negIndex] = arr[i]; negIndex += 2; same for the positive case and returning the ans.
//            TC -> O(n), SC -> O(n)

// Variety 2 CodeStudio - going back to the bruteforce approach. run a loop and store -ve and +ve elements in 2 vectors. now there are two cases
//              either pos.size>neg.size or vise-versa. now using a loop, iterating through given array to storing elements 
//              patternwise(first +ve then -ve) till one vector gets exausted. then w/ second loop storing remaining +ve elements 
//              in given arr. same concept for the neg.size > pos.size case.
//              TC -> O(n), SC -> O(n)

// Variety 2 GFG - storing +ve and -ve elements in 2 vectors respectively. using three ints (i,j,k, = 0) to iterate through given arr. 
//              w/ first while loop storing elements patternwise(first +ve then -ve) till vector gets exausted. then w/ other two while
//              loops storing remaining elements in arr.
//              TC-> O(n),SC->O(n)



vector<int> rearrangeArrayBrute(vector<int>& nums) {
		int n = nums.size();
        vector<int> posArr;
	    vector<int> negArr;
	    for(int i=0; i<n;i++){
	        if(nums[i] < 0){
	            negArr.push_back(nums[i]);
	        }
	        else if(nums[i] > 0){
	            posArr.push_back(nums[i]);
	        }
	    }
	    for(int i=0; i<n/2;i++){
	        nums[2*i] = posArr[i];
	        nums[2*i+1] = negArr[i];
	        
	    }
			return nums;
    }
    

    vector<int> rearrangeArrayOptimal(vector<int>& nums) {
		int n = nums.size();
	    vector<int> ans(n,0);
        int posIndex = 0, negIndex = 1;
	    for(int i=0; i<n;i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex+=2;
            } else {
                ans[posIndex] = nums[i];
                posIndex+=2;
            }
	    }
        return ans;
    }

    // Variety 2 - CodeStudio
    vector<int> alternateNumbers(vector<int>&arr) {
		int n = arr.size();
        vector<int> pos;
	    vector<int> neg;
	    
        // getting +ve and -ve numbers in arrays
	    for(int i=0; i<n;i++){
	        if(arr[i] < 0){
	            neg.push_back(arr[i]);
	        } else {
                pos.push_back(arr[i]);
	        }
	    }
	    
	    
	    if(pos.size() > neg.size()){
            // storing in pattern like first element +ve second -ve
	        for(int i=0; i < neg.size(); i++){
	            arr[i*2] = pos[i];
	            arr[2*i+1] = neg[i];
	        }
            // after that, storing remaining +ve elements in given arr
	        int index = neg.size() * 2;
	        for(int i = neg.size(); i<pos.size(); i++){
	            arr[index] = pos[i];
	            index++;
	        }
	    } else {
            // storing in pattern like first element +ve second -ve
	        for(int i=0; i < pos.size(); i++){
	            arr[i*2] = pos[i];
	            arr[2*i+1] = neg[i];
	        }
             // after that, storing remaining -ve elements in given arr
	        int index = neg.size() * 2;
	        for(int i = pos.size(); i<neg.size(); i++){
	            arr[index] = neg[i];
	            index++;
	        }
	    }
        return arr;
}

// Variety 2 - gfg
void rearrange(int arr[], int n) {
	    vector<int> pos;
	    vector<int> neg;
	    
	    for(int i=0; i<n;i++){
	        if(arr[i] < 0){
	            neg.push_back(arr[i]);
	        } else {
                pos.push_back(arr[i]);
	        }
	    }
	    
	    
	    int i=0, j=0, k=0;
	    while(i<pos.size() && j<neg.size()){
	        if(k%2 == 0){
	            arr[k] = pos[i];
	            i++;
	            k++;
	        }
	        else{
	            arr[k] = neg[j];
	            k++;
	            j++;
	        }
	    }
	    while(i < pos.size()){
	        arr[k] = pos[i];
	            i++;
	            k++;
	    }
	    while(j < neg.size()){
	        arr[k] = neg[j];
	            k++;
	            j++;
	    }



