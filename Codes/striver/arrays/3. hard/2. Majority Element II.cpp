#include <bits/stdc++.h>
using namespace std;

// Observation - when we talk about more than n/3, that means there will be max 2 elemets we can get as answers. 
// eg arr - 5 5 6 2 3 5 5 3 2 , arr.size - 9 
//          if we are finding n/3 elements, ie 9/3 = 3. so more than 3 means 4 occurances of each element.
//          4+4 = 8 and the size of arr is 9. therefore max 2 elements is possible. 


// Bruteforce - Checking each element with other elements in array, and incrementing the count. if the count == 2 break &
//              return. Using nested for loops from i/j -> n. inside first for, checking if ans.size!=0 || ans[0] != nums[i] 
//              then declare cnt=0 and inner for loop, if nums[j]==nums[i] then cnt++, and after inner loop if the cnt>n/3
//              ans.p_b(nums[i]). also if ans.size() == 2, then break and return ans;
//              TC -> O(n2), SC -> O(1)


// Better - Using hasing. taking HashMap to store element & count as key and value.get value of n/3. after iteration 
//          through hashmap we will have every unique element in hashmap w/ element and its count and if the count is >n/2.
//          push that element in ans array & return it.
//          TC -> O(n) + O(logn) for ordered map, SC -> O(n)
//          TC -> O(n) + O(1) for unordered map (best+avg), O(n) + O(n) (worst), SC -> O(n)

// Optimal - initialize 4 ints. cnt1, cnt2 = 0 and ele1, ele2=INT_MIN. traversing through given array using a for loop(i=0->n)
//          1. if cnt1 == 0 || ele2 != nums[i] then cnt1++, ele1 = nums[i]. vise-versa for cnt2.
//          2. elseif the nums[i] == ele1, then cnt1++.  elseif the nums[i] == ele2, then cnt2++
//          3. else just decrement the cnt1 and cnt2;
//          after this loop ele1 and ele2 should have the ans elements in it. here, using another loop to check if these
//          elements are > n/3. if it is then pushing them into ans array and sorting it. and finally returning.
//          TC -> O(N) + O(N), SC -> O(1).





    vector<int> majorityElementBrute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(ans.size() == 0 || ans[0] != nums[i]){
                int cnt=0;
                for(int j=0; j<n; j++){
                    if(nums[j] == nums[i]){
                        cnt++;
                    }
                }
                if(cnt > n/3){
                    ans.push_back(nums[i]);
                }
            }
            if(ans.size() == 2){
                break;
            }
        }
        return ans;
        
    }


    vector<int> majorityElementBetter(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mpp;
        int n = nums.size();
        int mini = (int) (n/3)+1;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] == mini){
                ans.push_back(nums[i]);
            }
            if(ans.size == 2){
                break;
            }
        }
        sort(nums.begin(), nums.end());
        return ans;
    }




 vector<int> majorityElementOptimal(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0, cnt2=0;
        int ele1=INT_MIN, ele2=INT_MIN;

        for(int i=0; i<n; i++){
            if(cnt1==0 && ele2!=nums[i]){
                cnt1=1,
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                cnt2=1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else {
                cnt1--, cnt2--;
            }
        }

        vector<int> ans;
        cnt1=0, cnt2=0;
        for(int i=0; i<n ; i++){
            if(ele1 == nums[i]){
                cnt1++;
            }
            if(ele2==nums[i]){
                cnt2++;
            }
        }
        int mini = (int)(n/3) +1;
        if(cnt1 >= mini){
            ans.push_back(ele1);
        }
        if(cnt2 >= mini){
            ans.push_back(ele2);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }