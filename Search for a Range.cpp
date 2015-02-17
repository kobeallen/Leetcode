class Solution {
public:
    int BinarySearch1(int A[], int n, int target)
    {
        int left=0, right=n-1, mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(A[mid]>=target)
                right=mid;
            else
                left=mid+1;
        }
        if(A[left]!=target)
            return -1;
        else
            return left;
    }

    int BinarySearch2(int A[], int n, int target)
    {
        int left=0, right=n-1, mid;
        while(left<right)
        {
            mid=left+(right-left+1)/2;
            if(A[mid]<=target)
                left=mid;
            else
                right=mid-1;
        }
        if(A[left]!=target)
            return -1;
        else
            return left;
    }

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if(n==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(BinarySearch1(A, n, target));
        ans.push_back(BinarySearch2(A, n, target));
        return ans;
    }
};
