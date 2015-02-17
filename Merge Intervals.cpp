/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


bool CMP(const Interval &A, const Interval &B)
{
    if(A.start!=B.start)
        return A.start<B.start;
    else
        return A.end<B.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ans;
        Interval result;
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(), intervals.end(), CMP);
        int i=0, j, size=intervals.size();
        while(i<size)
        {
            result.start=intervals[i].start;
            result.end=intervals[i].end;
            j=i+1;
            while(j<size&&intervals[j].start<=result.end)
            {
                if(intervals[j].end>result.end)
                    result.end=intervals[j].end;
                j++;
            }
            ans.push_back(result);
            i=j;
        }
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

bool CMP(Interval a, Interval b)
{
    if(a.start != b.start)
        return a.start < b.start;
    else
        return a.end < b.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), CMP);
        int i = 0;
        while(i < intervals.size())
        {
            int start = intervals[i].start;
            int end = intervals[i].end;
            int j = i + 1;
            while(j < intervals.size() && end >= intervals[j].start)
            {
                if(end < intervals[j].end)
                    end = intervals[j].end;
                ++j;
            }
            Interval newOne(start, end);
            ans.push_back(newOne);
            i = j;
        }
        return ans;
    }
};
