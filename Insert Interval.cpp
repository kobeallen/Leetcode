class Solution
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		vector<Interval> ans;
		int i=0;
		Interval a;
		while(i<intervals.size())
		{
			if(intervals[i].end>=newInterval.start)
				break;
			ans.push_back(intervals[i]);
			i++;
		}
		if(i==intervals.size())
			ans.push_back(newInterval);
		else
		{
			if(intervals[i].start<=newInterval.start)
				a.start=intervals[i].start;
			else
				a.start=newInterval.start;
            a.end=newInterval.end;
			while(i<intervals.size())
			{
				if(intervals[i].start>newInterval.end)
					break;
                if(a.end<intervals[i].end)
                    a.end=intervals[i].end;
				i++;
			}
			ans.push_back(a);
			while(i<intervals.size())
			{
				ans.push_back(intervals[i]);
				i++;
			}
		}
		return ans;
	}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        vector<Interval> ans;
        while(i < intervals.size() && intervals[i].end < newInterval.start)
        {
            ans.push_back(intervals[i]);
            ++i;
        }
        int start = newInterval.start;
        int end = newInterval.end;
        while(i < intervals.size())
        {
            if(intervals[i].start > newInterval.end)
                break;
            if(start > intervals[i].start)
                start = intervals[i].start;
            if(end < intervals[i].end)
                end = intervals[i].end;
            ++i;
        }
        Interval newOne(start, end);
        ans.push_back(newOne);
        while(i < intervals.size())
        {
            ans.push_back(intervals[i]);
            ++i;
        }
        return ans;
    }
};