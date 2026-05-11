class Solution {
public:

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int prevHeight) {
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() ||
        visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        visited[r][c] = true;
        //call dfs all direction
        dfs(heights, visited, r+1, c, heights[r][c]);
        dfs(heights, visited, r-1, c, heights[r][c]);
        dfs(heights, visited, r, c+1, heights[r][c]);
        dfs(heights, visited, r, c-1, heights[r][c]);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*  This problem revolves around the thing that 
            if going downhill means water will reach to both islands 
            then going uphill from ocean gives the same answer
        */

        if(heights.empty()) return {};

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int i=0; i<rows; i++) {
            //rows are moving - columns are still 
            //pacific left and atlantic right
            dfs(heights, pacific, i, 0, heights[i][0]); //0th col -> rows move
            dfs(heights, atlantic, i, cols-1,heights[i][cols-1]); //nth col -> rows move
        }


        for(int i=0; i<cols; i++) {
            //rows are moving - columns are still 
            //pacific left and atlantic right
            dfs(heights, pacific, 0, i,heights[0][i]); //0th col -> rows move
            dfs(heights, atlantic, rows-1, i,heights[rows-1][i]); //nth col -> rows move
        }

        vector<vector<int>> res;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
