class WordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isWord = false;
    };
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char c: word) {
            int index = c - 'a';
            if(node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int pos, TrieNode* node) {
        if (pos == word.size()) {
            return node->isWord;
        }

        char c = word[pos];

        //for the special case of '.'
        if(c == '.') {
            //check for all values/childrens
            for(int i=0; i<26; i++) {
                if(node->children[i] != nullptr) {
                    if(dfs(word, pos+1, node->children[i])) return true;
                }
            }
            return false;
        }

        int index = c - 'a';
        //for general word
        if(node->children[index] == nullptr){
            return false;
        }

        return dfs(word, pos+1, node->children[index]);


    }
};
