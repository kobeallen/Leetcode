class Solution
{
public:
	void Rotate(vector<vector<int> > &s, vector<vector<int> > &d)
	{
		int row=s.size(), col=s[0].size();
		int i,j;
		for(j=0;j<col;j++)
		{
			for(i=0;i<row;i++)
			{
				d[j][row-1-i]=s[i][j];  // The rotate is clockwise. If the rotate is anti-clockwise, it should be "d[col-1-j][i]=s[i][j]"
			}
		}
	}

	void rotate(vector<vector<int> > &matrix)
	{
		if(matrix.size()==0||matrix[0].size()==1)
			return ;
		vector<vector<int> > ans;
		int row=matrix.size(), col=matrix[0].size();
		int i,j;
		for(i=0;i<row;i++)
		{
			vector<int> t;
			for(j=0;j<col;j++)
			{
				t.push_back(0);
			}
			ans.push_back(t);
		}
		Rotate(matrix, ans);
		matrix=ans;
	}
};


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j;
        int row=matrix.size(), col=matrix[0].size();
        for(i=0;i<row;i++)
        {
            for(j=0;j<i;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(i=0;i<row;i++)  // Clockwise. If it's anticlockwise, switch elements in each column
        {
            int left=0, right=col-1;
            while(left<right)
            {
                int temp=matrix[i][left];
                matrix[i][left]=matrix[i][right];
                matrix[i][right]=temp;
                left++, right--;
            }
        }
    }
};
