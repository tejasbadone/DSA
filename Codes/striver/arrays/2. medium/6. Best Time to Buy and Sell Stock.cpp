#include <bits/stdc++.h>
using namespace std;

// Soln - getting maxprofit from each elements of array and starting by setting the first element as minPrice. in a for loop getting
//        currentProfit using currentProfit = arr[i] - minPrice and updating the maxProfit and minPrice using max() and min() function.
//              TC -> O(n), SC -> O(1)




int maxProfit(vector<int>& arr) {
    int n = arr.size();
    int minPrice = arr[0];
    int maxProfit = 0;

    for(int i=0;i<n;i++){
        int currentProfit = arr[i] - minPrice;
        maxProfit = max(currentProfit, maxProfit);
        minPrice = min(minPrice, arr[i]);
    }
    return maxProfit;
}



