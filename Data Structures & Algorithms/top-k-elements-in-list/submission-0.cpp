class Solution {
public:
//Initial Plan: 
//Count frequency - sort - return top k 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> arrMap;
        for(auto num: nums) {
            arrMap[num]++;
        }

        vector<pair<int,int>> freq;
        for(auto i: arrMap) {
            freq.push_back({i.first, i.second});
        }

        //sorting
        sort(freq.begin(), freq.end(), [](auto& a, auto&b) {
            return a.second > b.second;
        });

        //final result getting K elements out of it 
        vector<int> res;
        for(int i=0; i<k; i++) {
            res.push_back(freq[i].first);
        }

        return res;
    }
};
