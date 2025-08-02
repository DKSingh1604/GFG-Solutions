/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void inorder(vector<int> &ans, Node* root){
        
        if(root == NULL) return;
        
        inorder(ans, root -> left);
        ans.push_back(root -> data);
        inorder(ans, root -> right);
        
        
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        
        vector<int> ans;
        
        inorder(ans, root);
        
        return ans;
        
    }
};