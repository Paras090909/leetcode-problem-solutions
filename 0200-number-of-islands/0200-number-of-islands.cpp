class Solution {

private:
    bool valid(int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
        return true;
    }


    void DFS( int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>&vis, int x[4], int y[4])
    {
        vis[i][j] = true;
        for(int k = 0; k < 4; k++){
            int i_dir = i + x[k];
            int j_dir = j + y[k];
            if(valid(i_dir, j_dir, m, n))
            {
                if(grid[i_dir][j_dir] == '1')
                {
                    if(vis[i_dir][j_dir] == false)
                    {
                        DFS(i_dir, j_dir, m, n, grid, vis, x, y);
                    }
                   
                }
               
            }
        }
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>>vis(m);

        for(int i = 0; i < m; i++){
            vector<bool>t(n, 0);
            vis[i] = t;
        }

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((grid[i][j] == '1') && (vis[i][j] == false))
                {
                    DFS(i, j, m, n, grid, vis, x, y);
                    res++;
                }
            }
        }
        return res;
    }
};