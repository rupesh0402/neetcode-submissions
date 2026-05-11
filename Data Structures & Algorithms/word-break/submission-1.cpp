class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), -1 );
        return dfs(s, wordDict, 0, dp);
    }

    bool dfs(string &s,  vector<string>& wordDict, int i, vector<int>& dp) {
        if(i == s.length()) { // if we reach end of word then the separation is done
            return true;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        for(auto w: wordDict) {
            if(i + w.length() <= s.length() && s.substr(i, w.length()) == w) {
                if(dfs(s, wordDict, i + w.length(), dp)) {
                    dp[i] = true;
                    return true;
                }
            }
        }
        dp[i] = false;
        return false;
    }
};
