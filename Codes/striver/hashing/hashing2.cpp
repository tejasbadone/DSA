//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void topK(vector<int>& nums, int k) {

        map<int , int> mpp;
        vector<int> ans;

        cout << nums.size();

        for(int i=1; i<nums.size(); i++){
            mpp[nums[i]] +=1;
        }
        // for(int i=1; i<nums.size(); i++){
        //     cout << mpp[i] << " ";
        // }
        // return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int arr[7];

    for(int i=0; i< 7; i++){
        cin >> arr[i];
    }
    for(int i=0; i< 7; i++){
        cout <<  arr[i];
    }

    topK(arr, 2)
    
    return 0;
}
// } Driver Code Ends