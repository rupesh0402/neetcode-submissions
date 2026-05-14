class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> inter;
        
        for(auto& interval: intervals) {
            if(interval[1] < newInterval[0]) {
                inter.push_back(interval);
            } else if(interval[0] > newInterval[1]) {
                inter.push_back(newInterval);
                newInterval = interval;
            } else {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
            
        }
        inter.push_back(newInterval);
        return inter;
    }
};
