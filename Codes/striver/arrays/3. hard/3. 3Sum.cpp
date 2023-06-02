#include <bits/stdc++.h>
using namespace std;

// Bruteforce - Using three nested for loops, and a set st to store unique set of elements. i=0 -> n, j=i+1 -> n, k=j+1 -> n
//              and check if a[i]+a[j]+a[k] == 0, store three elements in a temp array, sort it and push into set. after 
//              loops declare vector<vector<int>> ans(st.begin(), st.end()) & return ans.
//              TC -> O(n3) + log(no of triplets) -> O(n3), unordered set -> O(n3) + O(1)
//              SC -> 2*O(no of triplets)

// Better - (approach) Using Hashing. To reduce TC we are finding third triplet from the first two(i&j) by using int k = -(a[i] + a[j]) finding the 
//          third element in set.

//          (explanation) declare set1 to store unique elements, initialize a for loop i=0 -> n & declare a hashset in it 
//          so that at every iteration it should start from 0. now, another for loop j=i+1 -> n and inside calculate the third
//          triplet by int k = -(a[i] + a[j]) and finding it in hashset. if it is present storing a[i], a[j], k in temp 
//          vector, sort it and store it in set1. after if loop, push a[j] in hashset to add j in hashset so that we can find
//          elements in hashset from i -> j. declare vector<vector<int>> ans(st.begin(), st.end()) and return it.
//          TC -> O(n2) * logm -> O(n2), where m is variable in hashset. unordered set -> O(n2) * O(1)
//          SC -> O(n) + O(no of triplets) * 2

// Optimal - Using 2 pointer approach. sorting given array. taking three variables i =0, j=i+1, k=n-1. taking sum of three vars
//          and if the sum is <0 then j++. else if sum>0 k--. if not any ie sum ==0, therefore push triplets in temp arr & push
//          it in ans & whlie(j<k) and if nums[j] == nums[j-1] then j++. also nums[k] == nums[k+1] k--; return ans.
//          TC -> O(nlogn) + O(n*n) -> O(n2)
//          SC -> O(no of triplets)








    vector<vector<int>> threeSumBrute(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;

    }

    vector<vector<int>> threeSumBetter(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i=0; i<n; i++){
            set<int> hashset;
            for(int j=i+1; j<n; j++){
                int third = - (nums[i] + nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;

    }

    vector<vector<int>> threeSumOptimal(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                } 
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--; 
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k]== nums[k+1]) k--;
                }
            }
        }
        return ans;

    }