class Solution {
public:
    // Adjacency Matrix
    // bool dfs(vector<vector<bool>>& graph, int src, int dst, vector<bool>& vis, int n){
    //     // Agar source hi dest he to we have path to it.
    //     if(src == dst) return true;
        
    //     // first thing mark source as vistited & go to all neighbours of source
    //     vis[src] = true;
    //     for(int i=0;i<n;i++){
    //         if(graph[src][i] && !vis[i]){
    //             // Agar dfs return true then we have path
    //             if(dfs(graph,i,dst,vis,n)){                     
    //                 return true; 
    //             }
    //         }
    //     }
    //     return false;
    // }
    // // Solve using DFS and Adjacency Matrix
    // bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    //     //form a graph/adjacency matrix
    //     vector<vector<bool>> graph(n,vector<bool>(n,false));

    //     for(auto edge:edges){
    //         int u = edge[0], v = edge[1];
    //         graph[u][v] = true;
    //         graph[v][u] = true; // as graph bi-directional            
    //     }

    //     //visited array of size n with all initially false as not visited.
    //     vector<bool> vis(n,false);

    //     //write a recusive function for dfs
    //     return dfs(graph,source,destination,vis,n);
    // }
    
    // // Solve using DFS and Adjacency Matrix
    // bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    // {
    //     //form a graph/adjacency matrix
    //     vector<vector<bool>> graph(n,vector<bool>(n,false));

    //     for(auto edge:edges){
    //         int u = edge[0], v = edge[1];
    //         graph[u][v] = true;
    //         graph[v][u] = true; // as graph bi-directional            
    //     }

    //     // visited array of n size, mark all false
    //     vector<bool> vis(n,false);
    //     vis[source] = true;

    //     //queue
    //     queue<int> q;
    //     q.push(source);

    //     //BFS logic
    //     while(!q.empty()){
    //         int curr = q.front();
    //         q.pop();

    //         if(curr == destination){
    //             return true;
    //         }

    //         for(int i=0;i<n;i++){
    //             if(graph[curr][i] && !vis[i]){
    //                 q.push(i);
    //                 vis[i] = true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool dfs(unordered_map<int,vector<int>>& graph, int src, int dst, vector<bool>& vis, int n){
        if(src == dst) return true;
        //visit the all the neighbours of source
        vis[src] = true;
        for(auto neg:graph[src]){
            if(!vis[neg]){
                if(dfs(graph,neg,dst,vis,n)){
                    return true;
                }
            }
        }
        return false;
    }
    //Solve using DFS and Adjacency List
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        //form a graph
        unordered_map<int,vector<int>> graph;
        for(auto edge:edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u); // as graph bi-directional
        }

        //visited array
        vector<bool> vis(n, false);

        return dfs(graph,source,destination,vis,n);
    }
};