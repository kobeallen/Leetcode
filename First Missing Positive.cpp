class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for(int i = 0; i < n; ++i)
        {
            int num = A[i];
            while(num > 0 && num <= n && num - 1 != i && A[num-1] != num)
            {
                int tmp = A[i];
                A[i] = A[num-1];
                A[num-1] = tmp;
                num = A[i];
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(A[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
