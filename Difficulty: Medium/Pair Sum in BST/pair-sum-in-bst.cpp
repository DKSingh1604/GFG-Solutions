/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool findTarget(Node *root, int target) {
        vector<int> container;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            container.push_back(node -> data);
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        unordered_map<int, int> storage;
        int n = (int)container.size();
        for (int i = 0; i < n; i++) {
            int current = container[i];
            if (storage.find(target - current) != storage.end()) return true;
            storage[current] = i;
        }
        return false;
    }
};