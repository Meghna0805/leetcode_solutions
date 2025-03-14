class Solution {
public:
    typedef pair<int, int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false); //to track the visited nodes
        priority_queue<P, vector<P>, greater<P>> minHeap;
        //start from node 0
        minHeap.push({0,0});
        int minCost = 0;
        int edgesUsed = 0; //No. of edges added

        while(edgesUsed < n){
            auto[cost, node] = minHeap.top();
            minHeap.pop();

            //If node is already visited, continue
            if (visited[node]) continue;

            //Mark as visited and cost add krdo
            visited[node] = true;
            minCost += cost;
            edgesUsed++;

            //Processing all unvisited neighbors
            for(int i =0; i<n; i++){
                if(!visited[i]){
                    int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    minHeap.push({dist, i});
                }
            }
        }
        return minCost;

    }
};