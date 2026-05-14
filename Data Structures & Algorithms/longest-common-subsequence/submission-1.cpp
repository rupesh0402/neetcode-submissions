class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return dfs(0, 0, text1, text2, dp);
    }

    int dfs(int i, int j, string t1, string t2, vector<vector<int>> dp) {
        if(i == t1.size() || j == t2.size()){
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(t1[i] == t2[j]) {
            return dp[i][j] = 1 + dfs(i+1, j+1, t1, t2, dp);
        }

        return dp[i][j] = max(dfs(i+1, j, t1, t2, dp), dfs(i, j+1, t1, t2, dp));
    }
};
