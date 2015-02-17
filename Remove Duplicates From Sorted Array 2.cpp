class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)  return 0;
        int size = 0;
        if(A[0] == A[1])
            ++size;
        for(int i = size + 1; i < n; ++i)
        {
            if(A[size] != A[i])
            {
                ++size;
                A[size] = A[i];
                if(i + 1 < n && A[i+1] == A[size])
                {
                    ++size;
                    ++i;
                    A[size] = A[i];
                }
            }
        }
        return size + 1;
    }
};