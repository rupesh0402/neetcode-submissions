class Solution {
public:
    int maxArea(vector<int>& heights) {
        //Two pointer approach - finding max water that it can hold. 

        int l = 0;
        int r = heights.size() - 1;

        int maxWater = 0;

        while(l < r) {
            int water = (r - l) * min(heights[l], heights[r]);
            maxWater = max(maxWater, water);

            if(heights[l] >= heights[r]) r--; else l++;
            
        }

        return maxWater;
    }
};
