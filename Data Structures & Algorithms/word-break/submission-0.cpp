class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict, 0);
    }

    bool dfs(string &s,  vector<string>& wordDict, int i) {
        if(i == s.length()) { // if we reach end of word then the separation is done
            return true;
        }

        for(auto w: wordDict) {
            if(i + w.length() <= s.length() && s.substr(i, w.length()) == w) {
                if(dfs(s, wordDict, i + w.length())) {
                    return true;
                }
            }
        }

        return false;
    }
};
