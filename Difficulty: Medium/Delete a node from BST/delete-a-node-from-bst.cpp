class Solution {
  public:
    // Function to delete a node from BST.
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    
    Node *deleteNode(Node *root, int X) {
        // your code goes here
        
        if(!root) return NULL;
        
        if(root -> data == X){
            if(!root -> left) return root -> right;
            else if(!root -> right) return root -> left;
            
            Node* successor = findMin(root -> right);
            root -> data = successor -> data;
            root -> right = deleteNode(root -> right, successor -> data);
        }
        else if(X > root -> data) root -> right = deleteNode(root -> right, X);
        else root -> left = deleteNode(root -> left, X);
        
        
        return root;
        
    }
};