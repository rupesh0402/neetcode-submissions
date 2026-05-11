class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        unordered_set<int> uniq;

        //insert all unique values
        for(int i: nums) {
            uniq.insert(i);
        }

        int cnt = 1;
        int longest = 1;

        for(auto i: uniq) {
            if(uniq.find(i-1) == uniq.end()) {
                int cnt = 1;
                int x = i;

                while(uniq.find(x+1) != uniq.end()) {
                    x = x + 1;
                    cnt++;
                }

            longest = max(longest, cnt);
            }
        }
        return longest;

    }
};
