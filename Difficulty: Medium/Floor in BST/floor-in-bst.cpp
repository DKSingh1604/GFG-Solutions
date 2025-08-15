// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        if (!root) return -1;
        
    
        if (root->data == x) return root->data;
    
       
        if (root->data > x) return floor(root->left, x);
    
        
        int rightFloor = floor(root->right, x);
        
        return (rightFloor <= x && rightFloor != -1) ? rightFloor : root->data;
    }
};