// 1207. Unique Number of Occurrences
// Easy

// 2003

// 47

// Add to List

// Share
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.

 

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
// Example 2:

// Input: arr = [1,2]
// Output: false
// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true
 

// Constraints:

// 1 <= arr.length <= 1000
// -1000 <= arr[i] <= 1000


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
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
};