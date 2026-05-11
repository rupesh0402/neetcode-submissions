class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums, 0, -1);
    }

    // Overlapping subproblems lead to DP memoization
    int dfs(vector<int>& nums, int ind, int prev) {

        if(ind == nums.size()) {
            return 0;
        }

        int res = dfs(nums, ind+1, prev); // we are not including you

        if(prev == -1 || nums[ind] > nums[prev]) {
            res = max(res, 1+dfs(nums, ind+1, ind));
        }

        return res;
     }
};
