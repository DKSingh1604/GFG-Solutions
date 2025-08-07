/*
struct Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> result;
        if (!root) return result;
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int qSize = q.size();
            vector<int> level(qSize);
            
            
            for(int i = 0; i < qSize; i++){
                Node* curr = q.front();
                q.pop();
                
                int index = leftToRight ? i : qSize - 1 - i;
                level[index] = curr -> data;
                
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
                
                
            }
            
            for(int val : level){
                result.push_back(val);
            }
            
            leftToRight = !leftToRight;
            
        }
        
        return result;
    }
};