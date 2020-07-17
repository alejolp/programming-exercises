/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool cmpInterval(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> R;
        int a, b;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmpInterval);
        for (a=0; a < intervals.size(); ) {
            Interval x = intervals[a];
            for (b=a+1; b < intervals.size(); ++b) {
                if (x.end >= intervals[b].start) {
                    x.end = max(x.end, intervals[b].end);
                } else {
                    break;
                }
            }
            R.push_back(x);
            a=b;
        }
        return R;
    }
};