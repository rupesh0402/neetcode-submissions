class Solution {
public:
    int uniquePaths(int m, int n) {
        //problem states that you have to move from 0,0 to m-1 n-1
        vector<vector<int>> dp (m, vector<int>(n, -1));
        return dfs(0,0,m,n, dp);
    }

    int dfs(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == (m-1) && j == (n-1)) { //path which takes us to the point
            return 1;
        }
        
        if(i>=m || j >= n) return 0; //not the path we want to go to
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = dfs(i+1, j, m, n, dp) + dfs(i, j+1, m, n, dp);
    }
};
