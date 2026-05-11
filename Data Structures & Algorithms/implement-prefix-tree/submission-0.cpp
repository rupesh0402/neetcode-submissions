class PrefixTree {

struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

private:
    TrieNode* root;
public:

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        //so insertion goes like this that you check if any character exist 
        //and if it doesn't you create a node and at the end mark the work isEnd = true
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        //now search works the similar way insert
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
       return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
       return true;
        
    }
};
