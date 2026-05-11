class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0];
        int maxProd = nums[0];
        int result = nums[0];

        for(int i=1; i< nums.size(); i++) {
            int temp_max = maxProd;
            int temp_min = minProd;

            int maxProd = max({nums[i], temp_max * nums[i], temp_min * nums[i]});

            int minProd = min({nums[i], temp_max * nums[i], temp_min * nums[i]});

            result = max(result, maxProd);
        }

        return result;
    }
};
