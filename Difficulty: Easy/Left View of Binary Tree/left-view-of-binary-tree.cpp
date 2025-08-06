/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(!root) return {};
        
        queue<Node*> q;
        q.push(root);
        
        vector<int> ans;
        
        while(!q.empty()){
            int levelSize = q.size();
            
            for(int i = 0; i < levelSize; i++){
                Node* node = q.front();
                q.pop();
                
                if(i == 0) ans.push_back(node -> data);
                
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                
            }
        }
        
        return ans;
        
    }
};