class Solution {
public:
    int trap(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int current_max = 0;
        for(int i = 0; i < n; ++i)
        {
            current_max = max(current_max, A[i]);
            left[i] = current_max;
        }
        current_max = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            current_max = max(current_max, A[i]);
            right[i] = current_max;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans += min(left[i], right[i]) - A[i];
        return ans;
    }
};
