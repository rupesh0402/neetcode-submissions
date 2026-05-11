class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //mathematical i guess - sum of numbers - sum of numbers present -> return whatever you get;

        int sum = reduce(nums.begin(), nums.end());
        cout << "sum " << sum; 
        int n = nums.size();

        int calcSum = (n * (n + 1))/2;

        cout << calcSum;
        return calcSum - sum;
    }
};
