/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans(2, nullptr); 
        
        Node* pred = nullptr;
        Node* succ = nullptr;
        Node* temp = root;
    
        
        while (temp && temp->data != key) {
            if (temp->data > key) {
                succ = temp;  
                temp = temp->left;
            } else {
                pred = temp;  
                temp = temp->right;
            }
        }
    
        if (!temp) {
            
            ans[0] = pred;
            ans[1] = succ;
            return ans;
        }
    
        
        if (temp->left) {
            Node* leftTree = temp->left;
            while (leftTree->right) {
                leftTree = leftTree->right;
            }
            pred = leftTree;
        }
    
        
        if (temp->right) {
            Node* rightTree = temp->right;
            while (rightTree->left) {
                rightTree = rightTree->left;
            }
            succ = rightTree;
        }
    
        ans[0] = pred;
        ans[1] = succ;
        return ans;
    }
};