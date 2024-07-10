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
private:
    void dfs(Node* oNode, Node* cNode, unordered_map<Node*, Node*>& m) {

        for (Node* oAdjNode : oNode->neighbors) {

            if (m.count(oAdjNode) == 0) {
                // as adj is not in map so create deep copy of adj
                Node* cAdjNode = new Node(oAdjNode->val);
                m[oAdjNode] = cAdjNode;
                cNode->neighbors.push_back(cAdjNode);
                dfs(oAdjNode, cAdjNode, m);
            } else {

                cNode->neighbors.push_back(m[oAdjNode]);
            }
        }
    }

public:
    Node* cloneGraph(Node* node) {

        if (!node)
            return nullptr;

        if (node->neighbors.empty())
            return new Node(node->val);

        unordered_map<Node*, Node*> m; // old to new
        // since we need to return deep copy so we need to clone all adj nodes
        // and push them into correct node neighbors vector
        Node* clonedNode = new Node(node->val);
        m[node] = clonedNode;

        // dfs(node,clonedNode,m);

        // Below BFS;
        queue<Node*> q; // pushing oNode as we need to fill cloned neighbors so
                        // crate copy of oNodes is bfs manner
        q.push(node);
        while (!q.empty()) {
            Node* oNode = q.front();
            q.pop();

            for (Node* oAdjNode : oNode->neighbors) {
                if (m.count(oAdjNode) == 0) {
                    // as adj is not in map so create deep copy of adj
                    Node* cAdjNode = new Node(oAdjNode->val);
                    m[oAdjNode] = cAdjNode;
                    m[oNode]->neighbors.push_back(cAdjNode);
                    q.push(oAdjNode);
                } else {

                    m[oNode]->neighbors.push_back(m[oAdjNode]);
                }
            }
        }

        return clonedNode;
    }
};