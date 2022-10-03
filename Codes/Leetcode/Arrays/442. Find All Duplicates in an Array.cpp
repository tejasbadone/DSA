// 442. Find All Duplicates in an Array
// Medium

// 7385

// 283

// Add to List

// Share
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        if(nums.empty()){
            return {};
        }
        
        vector<int> v; 

        sort(nums.begin() , nums.end());
        
        
        int j=nums[0];

        for(int i=1; i<nums.size(); i++){
            // cout << nums[i] << " ";
           if((j^nums[i])==0){
               v.push_back(nums[i]);
           }
                        
            j = nums[i];
            
        }
        
        return v;
    }
};