class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = 0;
        while(right < n)
        {
            if(A[right] != elem)
            {
                A[left] = A[right];
                ++left;
            }
            ++right;
        }
        return left;
    }   
};