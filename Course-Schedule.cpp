class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<int>& recStack, vector<vector<int>>& adj){
        visited[node] = true;
        recStack[node] = true;
        for(int neighbor: adj[node]){
            //check if the neighbor is visited
            if(!visited[neighbor]){
                //if its not visited then call dfs recursively and return true if recursive calls gives true
                if(dfs(neighbor, visited, recStack, adj)){
                    return true;
                }
            }
            //here check if the neighbor is already in recusion stack or not
            else if(recStack[neighbor]){
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto pre: prerequisites){
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
        }

        vector<int> visited(numCourses, false);
        vector<int> recStack(numCourses, false);

        for(int node=0; node<numCourses; node++){
            if(!visited[node]){
                if(dfs(node, visited, recStack, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};