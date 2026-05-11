/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfsSerialize(root, res);
        return res;
    }

    void dfsSerialize(TreeNode* root, string& res) {
        if(!root) {
            res+="N,";
            return ;
        }

        res+=to_string(root->val) + ",";
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dfsDeserialize(ss);
    }

    TreeNode* dfsDeserialize(stringstream& ss) {
        string val;
        getline(ss, val, ',');

        if(val == "N") {
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(val));
        node->left = dfsDeserialize(ss);
        node->right = dfsDeserialize(ss);

        return node;
    }
};
