class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left=0, right=n-1, mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(A[mid]>=target)
                right=mid;
            else
                left=mid+1;
        }
        if(A[left]<target)
            return n;
        return left;
    }
};
