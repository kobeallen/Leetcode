class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)  return 0;
        int size = 0;
        for(int i = 1; i < n; ++i)
        {
            if(A[size] != A[i])
            {
                ++size;
                A[size] = A[i];
            }
        }
        return size + 1;
    }
};