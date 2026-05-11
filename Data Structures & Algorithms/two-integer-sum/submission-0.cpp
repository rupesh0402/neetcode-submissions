class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value; 

        for(int i=0; i<= nums.size(); i++) {
            int complement = target - nums[i];
            if(value.find(complement) != value.end()) {
                return {value[complement], i};
            }
            value[nums[i]] = i;
        }
        return {};
    }
};
