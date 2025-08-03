/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int height(Node* root, int&maxi){
        if(root == NULL) return 0;
        
        int left = height(root -> left, maxi);
        int right = height(root -> right, maxi);
        
        maxi = max(maxi, left + right);
        
        return 1 + max(left, right);
    }
    
    int diameter(Node* root) {
        int maxi = 0;
        height(root, maxi);
        
        return maxi;
        
    }
};