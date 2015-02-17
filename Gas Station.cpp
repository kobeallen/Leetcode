class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> diff;
        int size = gas.size();
        if(size == 0)
            return -1;
        for(int i = 0; i < size; ++i)
            diff.push_back(gas[i] - cost[i]);
        for(int i = 0; i < size; ++i)
            diff.push_back(diff[i]);
        int left = 0, right = 0;
        int sum = 0;
        while(left < size)
        {
            while(right < 2 * size && sum >= 0)
            {
                if(right - left == size)
                    return left;
                sum += diff[right];
                ++right;
            }
            while(left < size && left < right && sum < 0)
            {
                sum -= diff[left];
                ++left;
            }
        }
        return -1;
    }
};