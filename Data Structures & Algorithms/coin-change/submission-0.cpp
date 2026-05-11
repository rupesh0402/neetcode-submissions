class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int res = solve(coins, amount, dp);
        return res == INT_MAX ? -1 : res;
    }

    int solve(vector<int>& coins, int amount, vector<int> &dp) {

        if(amount == 0) {
            return 0;
        }

        if(amount < 0) {
            return INT_MAX;
        }

        int mini = INT_MAX;

        if(dp[amount] != -1) {
            return dp[amount];
        }

        for(auto i: coins) {
            int ans = solve(coins, amount - i, dp);

            if(ans != INT_MAX) {
                mini = min(mini, 1 + ans);
            }
        }

        return dp[amount] = mini;
    }
};
