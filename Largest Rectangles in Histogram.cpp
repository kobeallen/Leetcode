class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < height.size(); ++i)
        {
            left.push_back(i);
            right.push_back(i);
        }
        for(int i = 0; i < height.size(); ++i)
        {
            while(left[i] > 0 && height[left[i] - 1] >= height[i])
            {
                left[i] = left[left[i] - 1];
            }
        }
        for(int i = height.size() - 1; i >= 0; --i)
        {
            while(right[i] < height.size() - 1 && height[right[i] + 1] >= height[i])
            {
                right[i] = right[right[i] + 1];
            }
        }
        int ans = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            int result = (right[i] - left[i] + 1) * height[i];
            if(ans < result)
                ans = result;
        }
        return ans;
    }
};