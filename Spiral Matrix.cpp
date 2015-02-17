class Solution {
public:
    void SpiralOrder(vector<vector<int> > ma, vector<int> &ans, int row, int col, int start)
    {
        if(row<=0||col<=0)
            return ;
        if(row==1)
        {
            for(int i=0;i<col;i++)
                ans.push_back(ma[start][start+i]);
            return ;
        }
        if(col==1)
        {
            for(int i=0;i<row;i++)
                ans.push_back(ma[start+i][start]);
            return ;
        }
        for(int i=0;i<col-1;i++)
            ans.push_back(ma[start][start+i]);
        for(int i=0;i<row-1;i++)
            ans.push_back(ma[start+i][start+col-1]);
        for(int i=0;i<col-1;i++)
            ans.push_back(ma[start+row-1][start+col-1-i]);
        for(int i=0;i<row-1;i++)
            ans.push_back(ma[start+row-1-i][start]);
        SpiralOrder(ma, ans, row-2, col-2, start+1);
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if(matrix.size()==0)
            return ans;
        SpiralOrder(matrix, ans, matrix.size(), matrix[0].size(), 0);
        return ans;
    }
};

class Solution {
public:
    void SpiralRotate(int low, int high, int left, int right, vector<vector<int> > matrix, int rotate, int X[], int Y[], vector<int> &ans)
    {
        int x, y;
        if(rotate == 0)
            x = low, y = left;
        else if(rotate ==  1)
            x = low, y = right;
        else if(rotate == 2)
            x = high, y = right;
        else if(rotate == 3)
            x = high, y = left;        
        while(x >= low && x <= high && y >= left && y <= right)
        {
            ans.push_back(matrix[x][y]);
            x += X[rotate];
            y += Y[rotate];
        }    
        if(rotate == 0)
            low += 1;
        else if(rotate == 1)
            right -= 1;
        else if(rotate == 2)
            high -= 1;
        else if(rotate == 3)
            left += 1;
        if(low <= high && left <= right)
            SpiralRotate(low, high, left, right, matrix, (rotate + 1) % 4, X, Y, ans);
    }
    
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        int X[] = {0, 1, 0, -1};
        int Y[] = {1, 0, -1, 0};
        if(matrix.empty())
            return ans;
        SpiralRotate(0, matrix.size() - 1, 0, matrix[0].size() - 1, matrix, 0, X, Y, ans);
        return ans;
    }
};

/*
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<int> ans;
        if(matrix.size()==0)
            return ans;
        int row=matrix.size(), col=matrix[0].size();
        vector<vector<bool> > hash;
        vector<bool> t;
        for(int i=0;i<col;i++)
            t.push_back(false);
        for(int i=0;i<row;i++)
            hash.push_back(t);
        int X[]={0, 1, 0, -1};
        int Y[]={1, 0,-1,  0};
        int id=0;
        int x=0, y=0;
        int count=0;
        while(count<row*col)
        {
            ans.push_back(matrix[x][y]);
            count++;
            hash[x][y]=true;
            if(x+X[id]<0||x+X[id]>=row||y+Y[id]<0||y+Y[id]>=col||hash[x+X[id]][y+Y[id]]==true)
                id=(id+1)%4;
            x+=X[id];
            y+=Y[id];
        }
        return ans;
    }
    // use constant space
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<int> ans;
        if(matrix.size()==0)
            return ans;
        int left_x=0, left_y=0;
        int right_x=matrix.size()-1, right_y=matrix[0].size()-1;
        int X[]={0, 1, 0, -1};
        int Y[]={1, 0,-1, 0};
        int id=0;
        int x=0, y=0;
        while(left_x<=right_x&&left_y<=right_y)
        {
            ans.push_back(matrix[x][y]);
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
*/
