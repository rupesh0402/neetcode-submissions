class Solution {
public:

    void dfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
        visited[node] = 1;

        for(auto& nei: graph[node]) {
            if(!visited[nei]) {
            dfs(graph, visited, nei);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n,0);
        int component = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]) {
                dfs(graph, visited, i);
                component++;
            }
        }
        return component;
    }
};
