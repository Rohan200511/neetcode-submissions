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
        int n = intervals.size();

        sort(intervals.begin() , intervals.end() , [](const Interval& a , const Interval& b){
            return a.start < b.start;
        });

        priority_queue<int , vector<int> , greater<int>>pq;

        for(auto& interval : intervals){
            int starting = interval.start;
            int ending = interval.end;

            if(!pq.empty() && pq.top() <= starting){
                pq.pop();
            }
            pq.push(ending);
        }
        return pq.size();
    }
};
