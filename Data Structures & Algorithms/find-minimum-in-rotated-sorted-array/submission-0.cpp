class Solution {
public:
    int findMin(vector<int> &nums) {
        //This problem is a modified binary search right 

        int l = 0, r = nums.size() - 1;
        int res = nums[l];

        while(l <= r) {
            if(nums[l] < nums[r]) {
                res = min(nums[l], res);
                break;
            }

            int mid = l + (r - l)/2;
            res = min(res, nums[mid]);
            if(nums[mid] >= nums[l]){
                //then the right side contains the answer 
                l = mid + 1;
            } else {
                r = mid - 1;
            }

        }

        return res;
    }
};
