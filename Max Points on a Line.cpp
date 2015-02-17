/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty())
            return 0;
        int ans = 1;
        unordered_map<double, int> hashMap;
        for(int i = 0; i < points.size(); ++i)
        {
            int samePoint = 1;
            int result = 0;
            hashMap.clear();
            for(int j = i + 1; j < points.size(); ++j)
            {
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    ++samePoint;
                    continue;
                }
                double slope = points[i].x == points[j].x ? INT_MAX : 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
                int tmp;
                unordered_map<double, int>::iterator it = hashMap.find(slope);
                if(it != hashMap.end())
                {
                    tmp = it->second + 1;
                    ++(it->second);
                }
                else
                {
                    tmp = 1;
                    hashMap.insert(pair<double, int>(slope, tmp));
                }
                if(result < tmp)
                    result = tmp;
            }
            if(ans < result + samePoint)
                ans = result + samePoint;
        }
        return ans;
    }
};