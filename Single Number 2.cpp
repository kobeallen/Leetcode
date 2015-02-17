class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int one = 0, two = 0, three = 0;
        int tmp1, tmp2;
        for(int i = 0; i < n; ++i)
        {
            tmp1 = one & A[i];
            tmp2 = two & A[i];
            one = ((one ^ tmp1) | (A[i] ^ tmp1)) ^ tmp2;
            two = (two ^ tmp2) | tmp1;
            three = three | tmp2;
        }
        return one;
    }
};