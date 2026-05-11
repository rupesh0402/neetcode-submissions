class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    void insert(string word, TrieNode* root) {
        TrieNode* node = root;
        
        for(char c: word) {
            int index = c - 'a';
            if(node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(auto& word : words) {
            insert(word, root);
        }

        vector<string> result;
        
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++) {
                dfs(board, r, c, root, result);
            }
        }
        
        return result;
    }

    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* node, vector<string>& result) {

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '#') {
            return ;
        }

        char ch = board[row][col];

        if(node->children[ch - 'a'] == nullptr) {
            return;
        }
        node = node->children[ch - 'a'];

        if(node->word != "") {
            result.push_back(node->word);
            node->word = "";
        }

        int index = ch - 'a';
        board[row][col] = '#';
        dfs(board, row+1,col,node,result);
        dfs(board, row-1,col,node,result);
        dfs(board, row,col+1,node,result);
        dfs(board, row,col-1,node,result);

        board[row][col] = ch;
    }

    
};
