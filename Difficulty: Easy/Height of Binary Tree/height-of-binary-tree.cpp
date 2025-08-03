/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
        // code here
        if(!node){
            return -1;
        }
        
        int left = height(node -> left);
        int right = height(node -> right);
        
        return 1 + max(left, right);
    }
};