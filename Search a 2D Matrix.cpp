// Below is O(row+col)
class Solution
{
public:
	bool matrix(vector<vector<int> > &matrix, int target)
	{
		if(matrix.size()==0)
			return false;
		int row=matrix.size(), col=matrix[0].size();
		int i=row-1, j=0;
		while(i>=0&&j<col)
		{
			if(matrix[i][j]==target)
				return true;
			else if(target>matrix[i][j])
				j++;
			else
				i--;
		}
		return false;
	}
};

// Below is O(Log(row*col))
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size()==0)
            return false;
        int row=matrix.size(), col=matrix[0].size();
        int left=0, right=row*col-1, mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(matrix[mid/col][mid%col]>=target)
                right=mid;
            else
                left=mid+1;
        }
        if(matrix[left/col][left%col]==target)
            return true;
        else
            return false;
    }
};
