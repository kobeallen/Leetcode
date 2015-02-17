class Solution {
public:    
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min = 1000000, pos_min;
        int max = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            if(min > prices[i])
                min = prices[i];
            if(max < prices[i] - min)
                max = prices[i] - min;
        }
        return max;
    }
};