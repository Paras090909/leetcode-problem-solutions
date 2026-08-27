class Solution {

private:
    bool valid(int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
        return true;
    }

    bool isEdge(int i, int j, int m, int n){ 
    return (i == 0 || i == m - 1 || j == 0 || j == n - 1);
    }

private:
    void DFS(vector<vector<char>>& board, int i, int j, int m, int n, vector<vector<int>>&vis, int x[4], int y[4]){
        vis[i][j] = 1;
            for(int k = 0; k < 4; k++){
                int new_i_dir = i + x[k];
                int new_j_dir = j + y[k];

                if(valid(new_i_dir, new_j_dir, m,n)){
                    if(board[new_i_dir][new_j_dir] == 'O' && vis[new_i_dir][new_j_dir] == 0){
                        DFS(board, new_i_dir, new_j_dir, m, n, vis, x, y);
                    }
                }
            }
        return;
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m);
        for(int i = 0 ; i < m; i++){
            vector<int>t(n, 0);
            vis[i] = t;
        }
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isEdge(i, j, m, n)){
                    if(board[i][j] == 'O' && vis[i][j] == 0){
                        DFS(board, i, j, m, n, vis, x, y);
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 1){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }

    }
};