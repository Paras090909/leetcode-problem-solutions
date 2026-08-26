class Solution {

private:
    void DFS(vector<vector<int>>& graph, int node, int c, vector<int>&colors, bool &res){
        colors[node] = c;

        for(int j = 0; j < graph[node].size(); j++){
            int neigh = graph[node][j];
            // check contradiction

            if(colors[neigh] != -1 && colors[neigh] == c){
                res = false;
            }

            if(colors[neigh] == -1){
                DFS(graph, neigh, 1-c, colors,res);
            }
        }
        return;
    }


public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n, -1);
        bool res = true;
        for(int i = 0; i < n; i++){
            if(colors[i] == -1){
                DFS(graph, i, 0, colors, res);
            }
        }
        return res;
    }
};