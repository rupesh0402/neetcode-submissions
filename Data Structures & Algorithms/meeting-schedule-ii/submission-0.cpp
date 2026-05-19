/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        //writing minheap approach to keep in mind the the minheap
        sort(intervals.begin(), intervals.end(), [](auto& a, auto&b) {
            return a.start < b.start;
        }); 
        //which meeting is starting first 

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(const auto& interval: intervals) { 
            if(!minHeap.empty() && minHeap.top() <= interval.start) {
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }

        return minHeap.size();
    }
};
