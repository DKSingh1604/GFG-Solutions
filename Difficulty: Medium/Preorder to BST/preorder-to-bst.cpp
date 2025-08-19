// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* build(int pre[], int &i, int bound, int size){
        
        if(i == size || pre[i] > bound) return NULL;
            
        Node* root = new Node();
        root -> data = pre[i++];
        root -> left = build(pre, i, root -> data, size);
        root -> right = build(pre, i, bound, size);
        return root;
        
    }
    Node* Bst(int pre[], int size) {
        // code here
        int i = 0;
        return build(pre, i, INT_MAX, size);
    }
};