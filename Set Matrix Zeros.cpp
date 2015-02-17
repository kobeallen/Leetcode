class Solution
{
public:
    int row=matrix.size(), col=matrix[0].size();
    int i,j;
    vector<int> R;
    vector<int> C;
    for(i=0;i<row;i++)
        R.push_back(1);
    for(i=0;i<col;j++)
        C.push_back(1);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(matrix[i][j]==0)
            {
                R[i]=0;
                C[j]=0;
            }
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(R[i]==0||C[j]==0)
            {
                matrix[i][j]=0;
            }
        }
    }
};



class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool firstRow = false, firstCol = false;
        for(int i = 0; i < matrix.size(); ++i)
        {
            if(matrix[i][0] == 0)
            {
                firstCol = true;
                break;
            }
        }
        for(int i = 0; i < matrix[0].size(); ++i)
        {
            if(matrix[0][i] == 0)
            {
                firstRow = true;
                break;
            }
        }
        for(int i = 1; i < matrix.size(); ++i)
        {
            for(int j = 1; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); ++i)
        {
            for(int j = 1; j < matrix[i].size(); ++j)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(firstRow == true)
        {
            for(int i = 0; i < matrix[0].size(); ++i)
                matrix[0][i] = 0;
        }
        if(firstCol == true)
        {
            for(int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        }
    }
};
