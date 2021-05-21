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
    unordered_map<Node*,Node*> map;
    Node* dfs(Node* node)
    {
        if(map.find()!=map.end()) return map[node];//if visited , return the node.
        Node* clone = new Node(node->val);//put the present node in clone.
        map[node]=clone;//mark visited
        for(Node* n:neighbors)
        {
            clone->neighbors.push_back(dfs(n));//to mark all the neighbours to the present node.
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
     if(node==nullptr) return node;
        return dfs(node);
       
    }
};
