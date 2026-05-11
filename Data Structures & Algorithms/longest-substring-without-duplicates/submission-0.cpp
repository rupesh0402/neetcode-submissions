class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> arr;
        int l = 0, r = 0;
        int max_len = 0;
        while(r < s.size()) {
            if(arr[s[r]] == 0) {
                arr[s[r]]++;
                max_len = max(max_len, r - l + 1);
                r++;
            } else {
                arr[s[l]]--;
                l+=1;
            }
        }
        return max_len;

    }
};
