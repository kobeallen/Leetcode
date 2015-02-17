class Solution
{
public:
    int Binary_Search(int target, int A[], int left, int right)
	{
		if(left==right)
		{
			if(target==A[left])
				return left;
			else
				return -1;
		}
		int mid=left+(right-left)/2;
		if(A[left]<=A[mid])
		{
			if(target>=A[left]&&target<=A[mid])
				return Binary_Search(target, A, left, mid);
			else
				return Binary_Search(target, A, mid+1, right);			
		}
		else
		{
			if(target>=A[mid+1]&&target<=A[right])
				return Binary_Search(target, A, mid+1, right);
			else
				return Binary_Search(target, A, left, mid);
		}
	}
	
	int search(int A[], int n, int target)
	{
		int ans=Binary_Search(target, A, 0, n-1);
		return ans;
	}
};