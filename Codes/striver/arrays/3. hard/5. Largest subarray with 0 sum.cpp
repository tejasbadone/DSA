// Bruteforce - Using nested loops, run a loop i=0 -> n and inside declare sum=0, now run another loop j=i -> n
//              and sum += a[j]. now check if sum ==0 then update maxi = max(maxi, j-i+1).
//              TC -> O(n2), SC - > O(1)

// Optimal - Using map, run a loop i=0 -> n, inside sum += a[i] and if sum == 0, then maxi = i+1. else check if sum is present
//           in map, if it is update maxi = max(maxi, i-mpp[sum]), if it is not present insert i in map.
//              TC -> O(n), SC -> O(n)







int maxLenOptimalBrute(vector<int>&A, int n)
{   
    int  max = 0;
	for(int i = 0; i < a.length; ++i){
		int sum = 0;
		for(int j = i; j < a.length; ++j){
			sum += a[j];
			if(sum == 0){
				max = Math.max(max, j-i+1);
			}
		}
	}
	return max;
        
}


int maxLenOptimal(vector<int>&A, int n)
    {   
        unordered_map<int,int> mpp;
        int sum=0;
        int maxi=0;
        
        for(int i=0; i<n; i++){
            sum += A[i];
            
            if(sum ==0){
                maxi = i+1;
            }
            else{
                if(mpp.find(sum) != mpp.end()){
                    maxi = max(maxi, i-mpp[sum]);
                }
                else{
                    mpp[sum] = i;
                }
            }
        }
        return maxi;
        
    }