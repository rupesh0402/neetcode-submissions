class Solution {
public:
    int ROWS, COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        
        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(dfs(board, word, r, c, 0)) return true;
            }
        }
        return false;

    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int i) {
        if(i == word.size()) {
            return true;
        }

        if(row < 0 || col < 0 || row >= ROWS || col >= COLS || 
            board[row][col] != word[i] || board[row][col] == '#') {
                return false;
            }

        board[row][col] = '#';
        bool res = dfs(board, word, row+1, col, i+1) || 
        dfs(board, word, row-1, col, i+1) || 
        dfs(board, word, row, col+1, i+1) || 
        dfs(board, word, row, col-1, i+1) ;

        board[row][col] = word[i];

        return res;
    };
};
