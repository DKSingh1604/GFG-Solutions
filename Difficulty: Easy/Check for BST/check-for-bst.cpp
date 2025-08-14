/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isValidBST(Node* root, int minVal, int maxVal){
        
        if(root == NULL) return true;
        
        if(root -> data >= maxVal || root -> data <= minVal) return false;
        
        return isValidBST(root -> left, minVal, root -> data) && isValidBST(root -> right, root -> data, maxVal);
    }
    
    bool isBST(Node* root) {
        // Your code here
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};