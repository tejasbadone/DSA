#include <bits/stdc++.h>
using namespace std;

// Bruteforce - Use nested for loop, if(a[i] == a[j]), then count++
//              T.C. -> O(n2), S.C. -> O(1)


// Better - Using map Hashing, storing elements as keys and counts as values.
//          TC -> O(nlogn) + O(n) -> O(nlogn), SC-> O(n)
//          unordered map TC -> O(n) for best & avg. O(n2) in worst .   SC -> O(n)


// Optimal - Using Moorie's Voting Algorithm. start with a 0th element in arr ie ele and make cnt=1, if the ele == element in arr then cnt++,
//           if not then reduce the cnt(ie cnt--). if the cnt reaches to 0, move the ele to the next element in array and make cnt=1.
//           till this step you should have the max element stored in ele. get its count and make sure its greater than n/2
//           Now, declare cnt1 and run a loop to get count of ele. also check if count1>n/2, then return ele. 
//           TC -> O(n), SC -> O(1) 



    int majorityElementBrute(int a[], int size)
    {
        
        
        for(int i=0; i<size;i++){
            int count=0;
            for(int j=0;j<size;j++){
                if(a[i] == a[j]){
                    count++;
                }
            }
            if(count > size/2){
                return a[i];
                break;
            }
        }
        return -1;
        
    }


    int majorityElementBetter(int a[], int size)
    {
        map<int, int> mpp;
        for(int i=0;i<size;i++){
            mpp[a[i]]++;
        }
        for(auto i: mpp){
            if(i.second > size/2){
                return i.first;
            }
        }
        return -1;
        
    }


    int majorityElementOptimal(int nums[])
    {   int n = nums.size();
        int count=0;
        int element;
        // value of counter count dosent represent anything here, it is just used to get the remaining max element of array in ele
        for(int i<0;i<n; i++){
            if(count==0){
                count=1;
                element = nums[i];
            }
            else if(nums[i] == element)
            {
                count++;
            }
            else{
                count--;
            }
            
        }

        // Confirming the max element by getting counter of ele and storing in count1
        int count1;
        for(int i=0; i<n; i++){
            if(nums[i] == element){
                count1++;
            }
            if(count1>n/2){
                return element;
            }
        }

        return -1;
        
    }





