#include <bits/stdc++.h>
using namespace std;


// Bruteforce - Using 2 nested loops, in first loop declaring bool leaders=true; and run another loop from i+1 -> n. if arr[j] > arr[i] 
//              then leader=false and break. after nested loop if leader == true then add arr[i] into an ans vector and return it. 
//              TC -> O(n2), SC -> O(n)


// Optimal - declaring lastHigh = INT_MIN and a ans vector. running a reverse loop ie from n-1 -> i>=0. if a[i] > lastHigh then adding that
//              element in ans vector. after if, update the lastHigh using max() fun. after loop just reverse the ans vector and return it.
//              TC -> O(n), SC -> O(n)

    vector<int> leadersBrute(int a[], int n){
        vector<int> ans;
        for(int i = 0; i<n; i++){
            bool leader = true;
            for(int j = i+1; j<n; j++){
                if(a[j] > a[i]){
                    leader = false;
                    break;
                }
            }
            if(leader == true){
                ans.push_back(a[i]);
            }
            // reverse(ans.begin(), ans.end());
        }
        return ans;
    }

    vector<int> Optimal(int a[], int n){
        int lasthigh = INT_MIN;
        vector<int> ans;
    
        for(int i=n-1; i>=0; i--){
            if(a[i] >= lasthigh){
                ans.push_back(a[i]);
            }
            lasthigh = max(lasthigh, a[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }