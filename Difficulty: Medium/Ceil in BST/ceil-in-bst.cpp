/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    
    if (!root) return -1;

    
    if (root->data == input) return root->data;

   
    if (root->data < input) return findCeil(root->right, input);

    
    int leftCeil = findCeil(root->left, input);
    
    return (leftCeil >= input && leftCeil != -1) ? leftCeil : root->data;
}