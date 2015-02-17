class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = prices.size();
        if(size == 0)
            return 0;        
        int ans1[size], ans2[size];
        memset(ans1, 0, sizeof(ans1));
        memset(ans2, 0, sizeof(ans2));
        int min = prices[0], max = prices[size-1];
        for(int i = 1; i < size; ++i)
        {
            if(min > prices[i]) min = prices[i];
            ans1[i] = ans1[i-1];
            if(ans1[i] < prices[i] - min)
                ans1[i] = prices[i] - min;
        }        
        for(int i = size - 2; i >= 0; --i)
        {
            if(max < prices[i]) max = prices[i];
            ans2[i] = ans2[i+1];
            if(ans2[i] < max - prices[i])
                ans2[i] = max - prices[i];
        }
        int ans = 0;
        for(int i = 0; i < size; ++i)
        {
            if(ans < ans1[i] + ans2[i])
                ans = ans1[i] + ans2[i];
        }
        return ans;
    }
};