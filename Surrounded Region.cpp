class Solution {
public:
    void DFS(vector<vector<char> > &board, int x, int y)
    {
        //if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
        //    return ;
        board[x][y] = 'T';
        if(x + 1 < board.size() && board[x + 1][y] == 'O')
            DFS(board, x + 1, y);
        if(x - 1 >= 0 && board[x - 1][y] == 'O')
            DFS(board, x - 1, y);
        if(y + 1 < board[0].size() && board[x][y + 1] == 'O')
            DFS(board, x, y + 1);
        if(y - 1 >= 0 && board[x][y - 1] == 'O')
            DFS(board,x, y - 1);
    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty()) return ;
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < col; ++i)
        {
            if(board[0][i] == 'O')
                DFS(board, 0, i);
            if(board[row - 1][i] == 'O')
                DFS(board, row - 1, i);
        }
        for(int i = 0; i < row; ++i)
        {
            if(board[i][0] == 'O')
                DFS(board, i, 0);
            if(board[i][col - 1] == 'O')
                DFS(board, i, col - 1);
        }
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};
