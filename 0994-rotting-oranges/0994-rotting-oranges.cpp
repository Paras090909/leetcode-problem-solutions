class Solution {

private:
    bool valid(int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), time = 0;
        int fresh = 0;
        queue<pair<int, int>>q;
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }else 
                if(grid[i][j] == 2){
                    q.push({i, j});
                    grid[i][j] = -2;
                }
            }
        }
        while(!q.empty() && fresh > 0){
            time++;
            int s = q.size();
            while(s--){
                pair<int, int>p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                for(int k = 0; k < 4; k++){
                    int nr = r + x[k];
                    int nc = c + y[k]; 
                    if(valid(nr, nc, m, n)){
                        if(grid[nr][nc] == 1){
                        q.push({nr, nc});
                        grid[nr][nc] = -2;
                        fresh--;
                    }
                }
                }
            }
        }
        if(fresh > 0) return -1;
        return time;
        
    }
};