/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>visited;
    Node* cloneGraph(Node* node) {
        //unordered_map<Node*, Node*>visited;
        if(!node) return nullptr;

        //if already cloned return the clone
        if(visited.find(node) != visited.end()){
            return visited[node];
        }
        //clone the current node
        Node* clone = new Node(node->val);
        visited[node] = clone;

        //clone the neighbour nodes
        for(Node* neighbor : node->neighbors){
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};