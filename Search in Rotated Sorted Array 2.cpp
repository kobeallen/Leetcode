class Solution {
public:
    bool BinarySearch(int A[], int left, int right, int target)
    {
        if(left==right)
        {
            if(A[left]==target)
                return true;
            else
                return false;
        }
        int mid=left+(right-left)/2;
        if(A[left]<A[mid])
        {
            if(A[left]<=target&&A[mid]>=target)
                return BinarySearch(A, left, mid, target);
            else
                return BinarySearch(A, mid+1, right, target);
        }
        else if(A[mid+1]<A[right])
        {
            if(A[mid+1]<=target&&A[right]>=target)
                return BinarySearch(A, mid+1, right, target);
            else
                return BinarySearch(A, left, mid, target);
        }
        else
            return BinarySearch(A, left, mid, target)||BinarySearch(A, mid+1, right, target);
    }
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return BinarySearch(A, 0, n-1, target);
    }
};