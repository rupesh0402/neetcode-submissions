class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> combined = nums;

        combined.insert(combined.end(), nums.begin(), nums.end());
        return combined;
    }
};