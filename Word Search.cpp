class Solution {
public:
    bool DFS(int x, int y, int depth, string word, vector<vector<char> > board, vector<vector<bool> > &hash, vector<vector<vector<bool> > > &dp, int X[], int Y[])
    {
        if(depth==word.size())
            return true;
        if(dp[x][y][depth]==false)
            return false;
        for(int i=0;i<4;i++)
        {
            if(x+X[i]>=0&&x+X[i]<board.size()&&y+Y[i]>=0&&y+Y[i]<board[0].size())
            {
                if(board[x+X[i]][y+Y[i]]==word[depth]&&hash[x+X[i]][y+Y[i]]==false)
                {
                    hash[x+X[i]][y+Y[i]]=true;
                    dp[x+X[i]][y+Y[i]][depth+1]=DFS(x+X[i], y+Y[i], depth+1, word, board, hash, dp, X, Y);
                    if(dp[x+X[i]][y+Y[i]][depth+1]==true)
                        return true;
                    hash[x+X[i]][y+Y[i]]=false;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.size()==0)
            return false;
        int row=board.size(), col=board[0].size(), length=word.size();
        int i,j;
        int X[]={0, 1, 0, -1};
        int Y[]={1, 0, -1, 0};
        vector<vector<vector<bool> > > dp;
        vector<vector<bool> > hash;
        vector<bool> t1;
        vector<vector<bool> > t2;
        for(i=0;i<length;i++)
            t1.push_back(true);
        for(i=0;i<col;i++)
            t2.push_back(t1);
        for(i=0;i<row;i++)
            dp.push_back(t2);
        t1.clear();
        for(i=0;i<col;i++)
            t1.push_back(false);
        for(i=0;i<row;i++)
            hash.push_back(t1);
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(board[i][j]==word[0])
                {
                    hash[i][j]=true;
                    dp[i][j][1]=DFS(i, j, 1, word, board, hash, dp, X, Y);
                    if(dp[i][j][1]==true)
                        return true;
                    hash[i][j]=false;
                }
            }
        }
        return false;
    }
};
