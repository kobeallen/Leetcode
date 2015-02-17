class Solution
{
public:
	void DFS(vector<string> &result, vector<vector<string> > &ans, int depth, int n, int X[], int Y[])
	{
		int x=depth, y;
		int tx, ty, i,j;
		if(depth==n)
		{
			ans.push_back(result);
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					printf("%c",result[i][j]);
				printf("\n");
			}
			printf("\n");
			return ;
		}		
		for(y=0;y<n;y++)
		{
			for(tx=x-1;tx>=0;tx--)
			{
				if(result[tx][y]=='Q')
					break;
			}
			if(tx>=0)
				continue;			
			for(i=0;i<4;i++)
			{
				tx=x, ty=y;
				while(tx>=0&&tx<n&&ty>=0&&ty<n)
				{
					if(result[tx][ty]=='Q')
						break;
					tx+=X[i];
					ty+=Y[i];
				}
				if(tx>=0&&tx<n&&ty>=0&&ty<n)
					break;
			}
			if(i<4)
				continue;
			result[x][y]='Q';						
			DFS(result, ans, depth+1, n, X, Y);
			result[x][y]='.';
		}
	}
	vector<vector<string> > solveNQueens(int n)
	{
		int X[]={-1, -1, 1, 1};
		int Y[]={-1,  1, 1,-1};
		string empty;
		vector<string> result;
		vector<vector<string> > ans;
		int i;
		for(i=0;i<n;i++)
			empty+='.';
		for(i=0;i<n;i++)
			result.push_back(empty);
		DFS(result, ans, 0, n, X, Y);
		return ans;
	}
};
