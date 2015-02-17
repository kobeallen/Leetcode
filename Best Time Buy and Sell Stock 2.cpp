class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        if(prices.size() == 0)
            return 0;
        int size = prices.size(), profit = 0, min = prices[0];
        for(int i = 1; i < size; ++i)
        {
            if(min < prices[i])
            {
                profit += prices[i] - min;
                min = prices[i];
            }
            else
                min = prices[i];
        }
        return profit;
    }
};