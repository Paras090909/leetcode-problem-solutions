class Solution {

private:
    void DFS(int idx, vector<int>&vis, vector<vector<int>>&adjacency_list){
        vis[idx] = 1;
        for(auto it : adjacency_list[idx]){
            if(!vis[it]){
                DFS(it, vis, adjacency_list);
            }
        }
        //return;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size(), n = isConnected[0].size();
        vector<vector<int>>adjacency_list(m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
               if(isConnected[i][j]==1  && i != j){
                adjacency_list[i].push_back(j);
                adjacency_list[j].push_back(i);
               } 
            }
        }
        int res = 0;
        vector<int>visited(m, 0);
        for(int i = 0; i < m; i++){
            if(!visited[i]){
                DFS(i, visited, adjacency_list);
                res++;
            }
        }
        return res;
    }
};