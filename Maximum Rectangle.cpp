class Solution {
public:
    void Preprocessing(vector<vector<int> > &count, vector<vector<char> > ma)
    {
        int row = ma.size(), col = ma[0].size();
        for(int i = 0; i < row; ++i)
        {
            if(ma[i][col-1] == '1')
                count[i][col-1] = 1;
            else
                count[i][col-1] = 0;
        }
        for(int i = col - 2; i >= 0; --i)
        {
            for(int j = 0; j < row; ++j)
            {
                if(ma[j][i] == '1')
                    count[j][i] = count[j][i+1] + 1;
                else
                    count[j][i] = 0;
            }
        }
    }
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > count (row, vector<int>(col, 0));
        Preprocessing(count, matrix);
        int ans = 0;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                int x = i, y = j;
                int width = 100000;
                while(x >= 0 && matrix[x][y] != '0')
                {
                    if(width > count[x][y])
                        width = count[x][y];
                    int height = i - x + 1;
                    int result = width * height;
                    if(result > ans)
                        ans = result;
                    --x;
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    void Preprocessing(vector<vector<int> > &count, vector<vector<char> > ma)
    {
        int row = ma.size(), col = ma[0].size();
        for(int i = 0; i < col; ++i)
        {
            if(ma[0][i] == '1')
                count[0][i] = 1;
            else
                count[0][i] = 0;
        }
        for(int i = 1; i < row; ++i)
        {
            for(int j = 0;j < col; ++j)
            {
                if(ma[i][j] == '1')
                    count[i][j] = count[i-1][j] + 1;
                else
                    count[i][j] = 0;
            }
        }
    }
    
    int MaxArea(vector<int> count)
    {
        int size = count.size();
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < size; ++i)
        {
            left.push_back(i);
            right.push_back(i);
        }
        for(int i = 1; i < size; ++i)
        {
            while(left[i] - 1 >= 0 && count[left[i] - 1] >= count[i])
                left[i] = left[left[i] - 1];
        }
        for(int i = size - 2; i >= 0; --i)
        {
            while(right[i] + 1 < size && count[right[i] + 1] >= count[i])
                right[i] = right[right[i] + 1];
        }
        int ans = 0;
        for(int i = 0; i < size; ++i)
        {
            int result = count[i] * (right[i] - left[i] + 1);
            if(result > ans)
                ans = result;
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > count (row, vector<int>(col, 0));
        Preprocessing(count, matrix);
        int ans = 0;
        for(int i = 0; i < row; ++i)
        {
            int result = MaxArea(count[i]);
            if(result > ans)
                ans = result;
        }
        return ans;
    }
};