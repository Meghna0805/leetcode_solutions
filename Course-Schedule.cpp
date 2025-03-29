class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        //Build Graph and indegree array
        for(auto& pre: prerequisites){
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }        

        //Create a queue to store the courses with indegree 0
        queue<int> q;
        //Start with all nodes with indegree 0
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;//count of courses that can be completed

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(int neighbor: adj[curr]){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return count == numCourses;
    }
};