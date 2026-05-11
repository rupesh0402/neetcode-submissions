class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProd(n), suffixProd(n), res(n);

        prefixProd[0] = 1;
        for(int i=1; i<n; i++) {
            prefixProd[i] = nums[i-1] * prefixProd[i-1];
        }

        suffixProd[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            suffixProd[i] = nums[i + 1] * suffixProd[i + 1];
        }

        for(int i =0; i<n; i++) {
            res[i] = suffixProd[i] * prefixProd[i];
        }

        return res;
    }
};
