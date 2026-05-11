class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return dfs(nums, 0, -1, dp);
    }

    // Overlapping subproblems lead to DP memoization
    int dfs(vector<int>& nums, int ind, int prev, vector<vector<int>> &dp) {

        if(ind == nums.size()) {
            return 0;
        }

        if(dp[ind][prev + 1] != -1) {return dp[ind][prev+1];}

        int res = dfs(nums, ind+1, prev, dp); // we are not including you

        if(prev == -1 || nums[ind] > nums[prev]) {
            res = max(res, 1+dfs(nums, ind+1, ind, dp));
        }

        return dp[ind][prev+1] = res;
     }
};
