class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto i: strs) {
            res += to_string(i.size()) + "#" + i; 
        }

        return res;

    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while(i < s.size()) {

            int j=i;
            while(s[j] != '#' && j < s.size()) {
                j++;
            }

            int len = stoi(s.substr(i, j-i));

            string word = s.substr(j + 1, len);
            res.push_back(word);
            
            // Move pointer
            i = j + 1 + len;
        }

        return res;
    }
};
