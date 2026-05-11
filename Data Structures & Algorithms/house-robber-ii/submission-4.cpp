class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1) {
            return nums[0];
        } 

        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> skipLast;
        vector<int> skipFirst;

        for(int i=0; i<nums.size() - 1; i++) {
            skipLast.push_back(nums[i]);
            skipFirst.push_back(nums[i+1]);
        }

        int last = robber(skipLast);
        int first = robber(skipFirst);

        return max(last, first);
    }

    int robber(vector<int>& nums) {
        
        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }

        return second;
    }
};
