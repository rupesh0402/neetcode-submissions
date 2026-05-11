class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> arr;

        for(auto i: strs) {
            string key = i;
            sort(key.begin(), key.end());
            arr[key].push_back(i);
        }

        vector<vector<string>> res;
        for(auto i: arr) {
            res.push_back(i.second);
        }
        return res;
    }
};
