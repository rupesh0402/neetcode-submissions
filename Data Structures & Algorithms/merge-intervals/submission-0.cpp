class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // first we can sort then we can use 1 active interval and then try merging it if required
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;

        output.push_back(intervals[0]);

        for(auto& interval : intervals) {
            int lastInterval = output.back()[1];

            if(interval[0] <= lastInterval) {
                output.back()[1] = max(lastInterval, interval[1]);
            } else {
                output.push_back(interval);
            }
        }
        return output;
    }
};
