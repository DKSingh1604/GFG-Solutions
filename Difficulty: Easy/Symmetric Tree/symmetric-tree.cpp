/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isMirror(Node* n1, Node* n2){
        
        //base cases
        if(!n1 && !n2) return true;
        
        if(!n1 || !n2) return false;
        
        //recursive relation
        
        return (n1 -> data == n2 -> data) && isMirror(n1 -> left, n2 -> right) && isMirror(n1 -> right, n2 -> left);
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(!root) return true;
        
        return isMirror(root -> left, root -> right);
    }
};