class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return dfs(0, 0, text1, text2);
    }

    int dfs(int i, int j, string t1, string t2) {
        if(i == t1.size() || j == t2.size()){
            return 0;
        }

        if(t1[i] == t2[j]) {
            return 1 + dfs(i+1, j+1, t1, t2);
        }

        return max(dfs(i+1, j, t1, t2), dfs(i, j+1, t1, t2));
    }
};
