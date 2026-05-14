class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(sum < 0) {
                sum = 0;
            }
            sum +=nums[i];
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};
