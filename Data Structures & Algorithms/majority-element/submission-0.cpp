class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore's voting algorithm 
        int ele = nums[0];
        int count=0;
        for(int i: nums) {
            if(count == 0) {
                ele = i;
            }
            if(ele == i) {
                count++;
            } else {
                count--;
            }
        }
        return ele;
    }
};