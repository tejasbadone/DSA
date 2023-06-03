
// Bruteforce - Using 4 loops, i=0 -> n, j=i+1 -> n, k=j+1 -> n & l=k+1 -> n. taking sum of all four (a[i], a[j], a[k], a[l])
//              and comparing with target, if it is ==target, storing them in temp vector & pushing into a set st(to avoid
//              duplicates) and finally declaring vector<vector<int>> ans(st.begin(), st.end()) and returning it.
//              TC -> O(n4), SC -> O(no of quards)*2

// Better - To optimise bruteforce, we will use 3 loops instead of 4. we will find the last element of quadruple by using
//          num[l] = target -(nums[i]+nums[j]+nums[k]) and find the nums[l] in hashset which stores the values bten j & k.
//          (not finding num[l] in arr cause we need distinct elements) everytime you move k, make sure to push it into
//          hashset. if we find element in hashset then we store all four quads in temp vector and then pushing into
//          set. finally declaring vector<vector<int>> ans(st.begin(), st.end()); and return it.
//          TC -> O(n3) * log(m) (m -> variable size in set), SC -> O(n) + O(no of quards)*2

// Optimal - Using 2 pointers approach. sort array. first 2 pointers(i&j) will be constant & will with rest 2 pointers(k&l)
//          we will not perform operations on duplicate elements. once the operations is performed on a value, if that
//          value appears again, we will skip it(skip all duplicates). set i=0, j=i+1, k=j+1 & l = n-1 and we will take sum
//          of all 4 and if it is == target store all in temp vector and push into ans(vector<vector<int>>), k++ and l--.
//          also at every step check if it is == previous element. if it is skip that element.
//          TC -> O(n3), SC ->  O(no. of quadruplets).





    vector<vector<int>> fourSumBrute(vector<int>& nums, int target) {
            int n = nums.size();
            set<vector<int>> st;

            for(int i=0; i<n ; i++){
                for(int j=i+1; j<n; j++){
                    for(int k=j+1; k<n; k++){
                        for(int l = k+1; l<n; l++){
                            long long sum = nums[i] + nums[j];
                            sum += nums[k];
                            sum += nums[l];

                            if(sum == target){
                                vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                                sort(temp.begin(), temp.end());
                                st.insert(temp);
                            }
                        }
                    }
                }
            }
            vector<vector<int>> ans(st.begin(), st.end());
            return ans;
    }


    vector<vector<int>> fourSumBetter(vector<int>& nums, int target) {
            int n = nums.size();
            set<vector<int>> st;

            for(int i=0; i<n ; i++){
                for(int j=i+1; j<n; j++){
                    set<long long> hashset;
                    for(int k=j+1; k<n; k++){
                        long long sum = nums[i] + nums[j];
                        sum+=nums[k];
                        long long forth = target - sum;
                        if(hashset.find(forth) != hashset.end()){
                            vector<int> temp = {nums[i], nums[j], nums[k],(int)forth};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                        
                        hashset.insert(nums[k]);
                    }
                }
            }
            vector<vector<int>> ans(st.begin(), st.end());
            return ans;
    }



    vector<vector<int> > fourSumOptimal(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j!=(i+1) && nums[j] == nums[j-1]) continue;
                int k=j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++; l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
