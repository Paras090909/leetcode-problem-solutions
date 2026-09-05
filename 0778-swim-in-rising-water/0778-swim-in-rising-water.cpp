class Solution {

private:
    bool valid(int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }

private:
    bool BFS(vector<vector<int>>& grid, int m, int n, int guess) {
        queue<pair<int, int>> q;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        vector<vector<int>> vis(m);
        for (int i = 0; i < m; i++) {
            vector<int> t(n, 0);
            vis[i] = t;
        }

        q.push({0, 0});
        vis[0][0] = 1;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if (row == m - 1 && col == n - 1)
                return true;
            for (int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];
                if (valid(r, c, m, n)) {
                    if (vis[r][c] == 0 && guess >= grid[r][c]) {
                        q.push({r, c});
                        vis[r][c] = 1;
                    }
                }
            }
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mini = grid[0][0];
        int maxi = grid[0][0];
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, grid[i][j]);
            }
        }
        while (mini <= maxi) {
            int guess = mini + (maxi - mini) / 2;
            if (BFS(grid, m, n, guess)) {
                res = guess;
                maxi = guess - 1;
            } else {
                mini = guess + 1;
            }
        }
        return res;
    }
};