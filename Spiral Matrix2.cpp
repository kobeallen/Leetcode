class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > ans;
        for(int i=0;i<n;i++)
        {
            vector<int> t;
            for(int j=0;j<n;j++)
                t.push_back(0);
            ans.push_back(t);
        }
        int X[]={0, 1, 0, -1};
        int Y[]={1, 0, -1, 0};
        int left_x=0, left_y=0;
        int right_x=n-1, right_y=n-1;
        int count=1;
        int x=0, y=0;
        int id=0;
        while(count<=n*n)
        {
            ans[x][y]=count;
            count++;
            if(x+X[id]>=left_x&&x+X[id]<=right_x&&y+Y[id]>=left_y&&y+Y[id]<=right_y)
            {
                x+=X[id];
                y+=Y[id];
            }
            else if(x+X[id]>=left_x&&x+X[id]<=right_x)
            {
                if(y+Y[id]<left_y)
                    right_x--;
                else if(y+Y[id]>right_y)
                    left_x++;
                id=(id+1)%4;
                x+=X[id];
                y+=Y[id];
            }
            else if(y+Y[id]>=left_y&&y+Y[id]<=right_y)
            {
                if(x+X[id]<left_x)
                    left_y++;
                else if(x+X[id]>right_x)
                    right_y--;
                id=(id+1)%4;
                x+=X[id];
                y+=Y[id];
            }
            else
                break;
        }
        return ans;
    }
};


class Solution {
public:
    void SpiralRotate(vector<vector<int> > &matrix, int row, int col, int start, int &index)
    {
        if(row <= 0 || col <= 0)
            return ;
        if(row == 1)
        {
            for(int i = 0; i < col; ++i)
            {
                matrix[start][start+i] = index++;                
            }
            return ;
        }
        if(col == 1)
        {
            for(int i = 0; i < row; ++i)
            {
                matrix[start+i][start] = index++;                
            }
            return ;
        }
        for(int i = 0; i < col - 1; ++i)
        {
            matrix[start][start+i] = index++;            
        }
        for(int i = 0; i < row - 1; ++i)
        {
            matrix[start+i][start+col-1] = index++;
        }
        for(int i = 0; i < col - 1; ++i)
        {
            matrix[start+row-1][start+col-1-i] = index++;
        }
        for(int i = 0; i < row - 1; ++i)
        {
            matrix[start+row-1-i][start] = index++;
        }
        SpiralRotate(matrix, row - 2, col - 2, start + 1, index);
    }
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int index = 1;
        SpiralRotate(matrix, n, n, 0, index);
        return matrix;
    }
};
